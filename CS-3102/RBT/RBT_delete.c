#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int data;
    int color;
    struct Node *L, *R, *P;
} *Node;

void fixDelete(Node *root, Node x) {
    while (x != *root && (x == NULL || x->color == BLACK)) {
        if (x == x->P->L) {
            Node w = x->P->R;
            if (w->color == RED) {
                w->color = BLACK;
                x->P->color = RED;
                leftRotate(root, x->P);
                w = x->P->R;
            }
            if ((w->L == NULL || w->L->color == BLACK) && 
                (w->R == NULL || w->R->color == BLACK)) {
                w->color = RED;
                x = x->P;
            } else {
                if (w->R == NULL || w->R->color == BLACK) {
                    if (w->L != NULL) w->L->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x->P->R;
                }
                w->color = x->P->color;
                x->P->color = BLACK;
                if (w->R != NULL) w->R->color = BLACK;
                leftRotate(root, x->P);
                x = *root;
            }
        } else {
            Node w = x->P->L;
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

Node minimum(Node node) {
    while (node->L != NULL) node = node->L;
    return node;
}

void delete(Node *root, Node z) {
    Node y = z, x;
    int y_original_color = y->color;

    if (z->L == NULL) {
        x = z->R;
        if (z->P == NULL) *root = x;
        else if (z == z->P->L) z->P->L = x;
        else z->P->R = x;
        if (x != NULL) x->P = z->P;
    } else if (z->R == NULL) {
        x = z->L;
        if (z->P == NULL) *root = x;
        else if (z == z->P->L) z->P->L = x;
        else z->P->R = x;
        if (x != NULL) x->P = z->P;
    } else {
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
