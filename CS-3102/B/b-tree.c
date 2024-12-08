#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the degree of the B-tree
#define DEGREE 3  // Minimum degree (T). A node can have at most 2*T-1 keys.

// Structure for a B-tree node
typedef struct BTreeNode {
    int keys[2 * DEGREE - 1];  // Keys in the node
    struct BTreeNode* children[2 * DEGREE];  // Pointers to child nodes
    int numKeys;  // Current number of keys
    bool isLeaf;  // True if node is a leaf
} BTreeNode;

// Create a new B-tree node
BTreeNode* createNode(bool isLeaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->isLeaf = isLeaf;
    node->numKeys = 0;
    for (int i = 0; i < 2 * DEGREE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to search for a key in the B-tree
BTreeNode* search(BTreeNode* root, int key) {
    int i = 0;

    // Find the first key greater than or equal to the search key
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }

    // If the key is found, return the current node
    if (i < root->numKeys && root->keys[i] == key) {
        return root;
    }

    // If the node is a leaf, the key is not present
    if (root->isLeaf) {
        return NULL;
    }

    // Recur to the appropriate child
    return search(root->children[i], key);
}

// Function to split a full child node
void splitChild(BTreeNode* parent, int index) {
    BTreeNode* fullChild = parent->children[index];
    BTreeNode* newChild = createNode(fullChild->isLeaf);
    newChild->numKeys = DEGREE - 1;

    // Move the last (DEGREE - 1) keys of the full child to the new child
    for (int j = 0; j < DEGREE - 1; j++) {
        newChild->keys[j] = fullChild->keys[j + DEGREE];
    }

    // Move the last DEGREE children of the full child to the new child (if not a leaf)
    if (!fullChild->isLeaf) {
        for (int j = 0; j < DEGREE; j++) {
            newChild->children[j] = fullChild->children[j + DEGREE];
        }
    }

    fullChild->numKeys = DEGREE - 1;

    // Shift parent's children to make space for the new child
    for (int j = parent->numKeys; j >= index + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[index + 1] = newChild;

    // Move the middle key of the full child to the parent
    for (int j = parent->numKeys - 1; j >= index; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[index] = fullChild->keys[DEGREE - 1];
    parent->numKeys++;
}

// Function to insert a key into a non-full node
void insertNonFull(BTreeNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // Shift keys to the right to make space for the new key
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find the child that will receive the new key
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        // If the child is full, split it
        if (node->children[i]->numKeys == 2 * DEGREE - 1) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }

        // Recur to the appropriate child
        insertNonFull(node->children[i], key);
    }
}

// Function to insert a key into the B-tree
BTreeNode* insert(BTreeNode* root, int key) {
    // If the root is full, split it
    if (root->numKeys == 2 * DEGREE - 1) {
        BTreeNode* newRoot = createNode(false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Function to print the B-tree (in-order traversal)
void printTree(BTreeNode* root, int level) {
    if (root) {
        for (int i = 0; i < root->numKeys; i++) {
            // Print children before the key
            if (!root->isLeaf) {
                printTree(root->children[i], level + 1);
            }
            printf("Level %d: %d\n", level, root->keys[i]);
        }

        // Print the last child
        if (!root->isLeaf) {
            printTree(root->children[root->numKeys], level + 1);
        }
    }
}

// Free the memory of the B-tree
void freeTree(BTreeNode* root) {
    if (root) {
        for (int i = 0; i <= root->numKeys; i++) {
            freeTree(root->children[i]);
        }
        free(root);
    }
}

// Example usage
int main() {
    BTreeNode* root = createNode(true);

    // Insert keys
    int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
    for (int i = 0; i < 8; i++) {
        root = insert(root, keys[i]);
    }

    printf("B-tree structure:\n");
    printTree(root, 0);

    // Search for a key
    int searchKey = 12;
    BTreeNode* result = search(root, searchKey);
    if (result) {
        printf("\nKey %d found in the B-tree.\n", searchKey);
    } else {
        printf("\nKey %d not found in the B-tree.\n", searchKey);
    }

    // Free the memory
    freeTree(root);

    return 0;
}