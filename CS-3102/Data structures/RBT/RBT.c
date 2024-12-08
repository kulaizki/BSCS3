#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int data;
    int color;
    struct Node *L, *R, *P;
} *Node;

// Function to create a new node
Node newNode(int data) {
    Node node = (Node)malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED;  // New nodes are always red
    node->L = node->R = node->P = NULL;
    return node;
}

// Left rotate function
void leftRotate(Node *root, Node x) {
    Node y = x->R;
    x->R = y->L;
    if (y->L != NULL) y->L->P = x;
    y->P = x->P;
    if (x->P == NULL) *root = y;
    else if (x == x->P->L) x->P->L = y;
    else x->P->R = y;
    y->L = x;
    x->P = y;
}

// Right rotate function
void rightRotate(Node *root, Node y) {
    Node x = y->L;
    y->L = x->R;
    if (x->R != NULL) x->R->P = y;
    x->P = y->P;
    if (y->P == NULL) *root = x;
    else if (y == y->P->L) y->P->L = x;
    else y->P->R = x;
    x->R = y;
    y->P = x;
}

// Fix the Red-Black Tree after insertion
void fixInsert(Node *root, Node z) {
    while (z != *root && z->P->color == RED) {
        if (z->P == z->P->P->L) {
            Node y = z->P->P->R;
            // Case 1: Uncle is red, recolor and move z up the tree
            if (y && y->color == RED) {
                z->P->color = BLACK;
                y->color = BLACK;
                z->P->P->color = RED;
                z = z->P->P;
            } else {
                // Case 2: z is on the right child, perform left rotation
                if (z == z->P->R) {
                    z = z->P;
                    leftRotate(root, z);
                }
                // Case 3: z is on the left child, perform right rotation
                z->P->color = BLACK;
                z->P->P->color = RED;
                rightRotate(root, z->P->P);
            }
        } else {
            Node y = z->P->P->L;
            // Symmetric cases for the other side of the tree
            if (y && y->color == RED) {
                z->P->color = BLACK;
                y->color = BLACK;
                z->P->P->color = RED;
                z = z->P->P;
            } else {
                if (z == z->P->L) {
                    z = z->P;
                    rightRotate(root, z);
                }
                z->P->color = BLACK;
                z->P->P->color = RED;
                leftRotate(root, z->P->P);
            }
        }
    }
    (*root)->color = BLACK; // Root must always be black
}

// Insert function for Red-Black Tree
void insert(Node *root, int data) {
    Node z = newNode(data);
    Node y = NULL;
    Node x = *root;

    // Binary Search Tree insert to find the correct place for the new node
    while (x != NULL) {
        y = x;
        if (z->data < x->data) x = x->L;
        else x = x->R;
    }

    z->P = y;
    if (y == NULL) *root = z;  // Tree was empty
    else if (z->data < y->data) y->L = z;
    else y->R = z;

    // Fix any violations of the Red-Black Tree properties
    fixInsert(root, z);
}

// In-order traversal function to print the tree
void inorderTraversal(Node root) {
    if (root == NULL) return;
    inorderTraversal(root->L);
    printf("%d ", root->data);
    inorderTraversal(root->R);
}

// Function to find the minimum node (leftmost child)
Node minimum(Node node) {
    while (node->L != NULL) node = node->L;
    return node;
}

// Function to fix the tree after deletion
void fixDelete(Node *root, Node x) {
    while (x != *root && (x == NULL || x->color == BLACK)) {
        if (x == x->P->L) {
            Node w = x->P->R;
            // Case 1: Sibling is red, rotate to fix
            if (w->color == RED) {
                w->color = BLACK;
                x->P->color = RED;
                leftRotate(root, x->P);
                w = x->P->R;
            }
            // Case 2: Both children of sibling are black
            if ((w->L == NULL || w->L->color == BLACK) && 
                (w->R == NULL || w->R->color == BLACK)) {
                w->color = RED;
                x = x->P;
            } else {
                // Case 3: Right child of sibling is black
                if (w->R == NULL || w->R->color == BLACK) {
                    if (w->L != NULL) w->L->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x->P->R;
                }
                // Case 4: Right child of sibling is red, rotate and fix
                w->color = x->P->color;
                x->P->color = BLACK;
                if (w->R != NULL) w->R->color = BLACK;
                leftRotate(root, x->P);
                x = *root;
            }
        } else {
            Node w = x->P->L;
            // Symmetric cases for the other side of the tree
            if (w->color == RED) {
                w->color = BLACK;
                x->P->color = RED;
                rightRotate(root, x->P);
                w = x->P->L;
            }
            if ((w->R == NULL || w->R->color == BLACK) && 
                (w->L == NULL || w->L->color == BLACK)) {
                w->color = RED;
                x = x->P;
            } else {
                if (w->L == NULL || w->L->color == BLACK) {
                    if (w->R != NULL) w->R->color = BLACK;
                    w->color = RED;
                    leftRotate(root, w);
                    w = x->P->L;
                }
                w->color = x->P->color;
                x->P->color = BLACK;
                if (w->L != NULL) w->L->color = BLACK;
                rightRotate(root, x->P);
                x = *root;
            }
        }
    }
    if (x != NULL) x->color = BLACK;
}

// Function to delete a node from the Red-Black Tree
void delete(Node *root, Node z) {
    Node y = z, x;
    int y_original_color = y->color;

    // Case 1: Node has no left child
    if (z->L == NULL) {
        x = z->R;
        if (z->P == NULL) *root = x;
        else if (z == z->P->L) z->P->L = x;
        else z->P->R = x;
        if (x != NULL) x->P = z->P;
    }
    // Case 2: Node has no right child
    else if (z->R == NULL) {
        x = z->L;
        if (z->P == NULL) *root = x;
        else if (z == z->P->L) z->P->L = x;
        else z->P->R = x;
        if (x != NULL) x->P = z->P;
    }
    // Case 3: Node has both children
    else {
        y = minimum(z->R);
        y_original_color = y->color;
        x = y->R;
        if (y->P == z) {
            if (x != NULL) x->P = y;
        } else {
            if (y->P != NULL) y->P->L = x;
            if (x != NULL) x->P = y->P;
            y->R = z->R;
            if (z->R != NULL) z->R->P = y;
        }
        if (z->P == NULL) *root = y;
        else if (z == z->P->L) z->P->L = y;
        else z->P->R = y;
        y->P = z->P;
        y->color = z->color;
        y->L = z->L;
        if (z->L != NULL) z->L->P = y;
    }
    if (y_original_color == BLACK) fixDelete(root, x);
}

// Main function
int main() {
    Node root = NULL;
    int a[] = {8, 18, 5, 15, 17, 25, 40, 80};
    int n = sizeof(a) / sizeof(a[0]);

    // Insert nodes into the Red-Black Tree
    for (int i = 0; i < n; i++) {
        insert(&root, a[i]);
    }

    // Print in-order traversal of the tree
    printf("In-order Traversal of RBT:\n");
    inorderTraversal(root);
    printf("\n");

    // Delete a node
    delete(&root, root); // Example of deletion: deleting the root
    printf("In-order Traversal after Deletion:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}