#include <stdio.h>
#include <stdlib.h>

// Structure for AVL Tree Node
typedef struct AVLNode {
    int key;
    int height;  // Height of the node
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

// Function to get the height of a node
int getHeight(AVLNode* node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to get the balance factor of a node
int getBalanceFactor(AVLNode* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right rotation
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    // Return the new root
    return x;
}

// Left rotation
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    // Return the new root
    return y;
}

// Function to insert a key in the AVL tree
AVLNode* insert(AVLNode* node, int key) {
    // Step 1: Perform the normal BST insert
    if (node == NULL) {
        AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;  // Duplicate keys are not allowed
    }

    // Step 2: Update the height of this ancestor node
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    // Step 3: Get the balance factor and balance the node
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to perform an inorder traversal of the tree
void inorderTraversal(AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to free the tree's memory
void freeTree(AVLNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Example usage
int main() {
    AVLNode* root = NULL;

    // Inserting nodes
    int keys[] = {10, 20, 30, 15, 25, 5, 1, 3};
    for (int i = 0; i < 8; i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);
    printf("\n");

    // Free the tree
    freeTree(root);

    return 0;
}
