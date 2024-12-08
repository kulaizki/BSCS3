#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the Binary Search Tree
typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Function to create a new node
BSTNode* createNode(int key) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the Binary Search Tree
BSTNode* insert(BSTNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in the Binary Search Tree
BSTNode* search(BSTNode* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function for in-order traversal of the Binary Search Tree
void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value node in the Binary Search Tree
BSTNode* findMin(BSTNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a key from the Binary Search Tree
BSTNode* deleteNode(BSTNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Find the node to delete
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found

        // Node with only one child or no child
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        BSTNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Example usage
int main() {
    BSTNode* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);  // Output: 20 30 40 50 60 70 80
    printf("\n");

    // Search for a value
    int searchKey = 60;
    BSTNode* searchResult = search(root, searchKey);
    if (searchResult != NULL) {
        printf("Found %d in the tree.\n", searchKey);
    } else {
        printf("Key %d not found in the tree.\n", searchKey);
    }

    // Delete a key
    printf("Deleting 20 from the tree.\n");
    root = deleteNode(root, 20);
    inorderTraversal(root);  // Output: 30 40 50 60 70 80
    printf("\n");

    return 0;
}
