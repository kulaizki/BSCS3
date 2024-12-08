#include <stdio.h>
#include <stdlib.h>

#define MIN_DEGREE 3  // Minimum degree (t)

typedef struct BStarNode {
    int *keys;
    int t;  // Minimum degree
    struct BStarNode **children;
    int n;  // Current number of keys
    int leaf;  // 1 if leaf node, 0 if internal node
} BStarNode;

// Create a new B*-Tree node
BStarNode* createNode(int t, int leaf) {
    BStarNode* node = (BStarNode*)malloc(sizeof(BStarNode));
    node->t = t;
    node->keys = (int*)malloc(sizeof(int) * (2 * t - 1));
    node->children = (BStarNode**)malloc(sizeof(BStarNode*) * (2 * t));
    node->n = 0;
    node->leaf = leaf;
    return node;
}

// Split the child of a node at index i
void splitChild(BStarNode* parent, int i, BStarNode* child) {
    int t = child->t;
    BStarNode* newChild = createNode(t, child->leaf);
    parent->children[i + 1] = newChild;
    parent->keys[i] = child->keys[t - 1];
    parent->n++;

    // Move the last (t-1) keys from child to newChild
    for (int j = 0; j < t - 1; j++) {
        newChild->keys[j] = child->keys[j + t];
    }

    // If child is not a leaf, move the children
    if (!child->leaf) {
        for (int j = 0; j < t; j++) {
            newChild->children[j] = child->children[j + t];
        }
    }

    // Update the number of keys in the child
    child->n = t - 1;
}

// Insert a key into a non-full B*-Tree node
void insertNonFull(BStarNode* node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        // Find the position for the new key
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    } else {
        // Find the child to insert the key
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;

        BStarNode* child = node->children[i];

        if (child->n == 2 * node->t - 1) {
            splitChild(node, i, child);

            if (node->keys[i] < key) {
                i++;
            }
        }

        insertNonFull(node->children[i], key);
    }
}

// Insert a key into the B*-Tree
void insert(BStarNode** root, int key) {
    BStarNode* r = *root;

    if (r->n == 2 * r->t - 1) {
        BStarNode* s = createNode(r->t, 0);
        *root = s;
        s->children[0] = r;
        splitChild(s, 0, r);
        insertNonFull(s, key);
    } else {
        insertNonFull(r, key);
    }
}

// Inorder traversal of the B*-Tree
void inorderTraversal(BStarNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            inorderTraversal(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        inorderTraversal(root->children[i]);
    }
}

// Free the memory allocated for the tree
void freeTree(BStarNode* root) {
    if (root != NULL) {
        for (int i = 0; i <= root->n; i++) {
            freeTree(root->children[i]);
        }
        free(root->keys);
        free(root->children);
        free(root);
    }
}

// Example usage
int main() {
    BStarNode* root = createNode(MIN_DEGREE, 1);

    // Insert values into the B*-Tree
    int values[] = {10, 20, 5, 6, 12, 30, 7, 17};
    for (int i = 0; i < 8; i++) {
        insert(&root, values[i]);
    }

    // Print the tree in inorder
    printf("Inorder traversal of the B*-Tree: ");
    inorderTraversal(root);
    printf("\n");

    // Free the tree
    freeTree(root);

    return 0;
}
