#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int data;
    int color;
    struct Node *L, *R, *P;
} *Node;

Node newNode(int data) {
    Node node = (Node)malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED; 
    node->L = node->R = node->P = NULL;
    return node;
}

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

void fixInsert(Node *root, Node z) {
    while (z != *root && z->P->color == RED) {
        if (z->P == z->P->P->L) {
            Node y = z->P->P->R;
            if (y && y->color == RED) {
                z->P->color = BLACK;
                y->color = BLACK;
                z->P->P->color = RED;
                z = z->P->P;
            } else {
                if (z == z->P->R) {
                    z = z->P;
                    leftRotate(root, z);
                }
                z->P->color = BLACK;
                z->P->P->color = RED;
                rightRotate(root, z->P->P);
            }
        } else {
            Node y = z->P->P->L;
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
    (*root)->color = BLACK;
}

void insert(Node *root, int data) {
    Node z = newNode(data);
    Node y = NULL;
    Node x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data) x = x->L;
        else x = x->R;
    }

    z->P = y;
    if (y == NULL) *root = z;
    else if (z->data < y->data) y->L = z;
    else y->R = z;

    fixInsert(root, z);
}

void inorderTraversal(Node root) {
    if (root == NULL) return;
    inorderTraversal(root->L);
    printf("%d ", root->data);
    inorderTraversal(root->R);
}

int main() {
    Node root = NULL;
    int a[] = {8, 18, 5, 15, 17, 25, 40, 80};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++) {
        insert(&root, a[i]);
    }

    printf("In-order Traversal of RBT:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}