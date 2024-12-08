#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEYS 3       // Maximum number of keys per node (degree 3)

typedef struct BPlusNode {
    int *keys;                   // Keys in the node
    struct BPlusNode **children; // Pointers to child nodes
    struct BPlusNode *next;      // Pointer to the next leaf node (for range queries)
    bool isLeaf;                 // True if the node is a leaf
    int numKeys;                 // Current number of keys in the node
} BPlusNode;

typedef struct BPlusTree {
    BPlusNode *root;  // Root of the B+ Tree
} BPlusTree;

// Function to create a new node
BPlusNode* createNode(bool isLeaf) {
    BPlusNode* newNode = (BPlusNode*)malloc(sizeof(BPlusNode));
    newNode->keys = (int*)malloc(sizeof(int) * MAX_KEYS);
    newNode->children = (BPlusNode**)malloc(sizeof(BPlusNode*) * (MAX_KEYS + 1));
    newNode->next = NULL;
    newNode->isLeaf = isLeaf;
    newNode->numKeys = 0;
    return newNode;
}

// Function to split a node when it overflows
void splitNode(BPlusTree *tree, BPlusNode *node, int i) {
    BPlusNode *newNode = createNode(node->isLeaf);
    int midKey = node->keys[MAX_KEYS / 2];

    // Move half of the keys and children to the new node
    for (int j = MAX_KEYS / 2 + 1; j < MAX_KEYS; j++) {
        newNode->keys[j - (MAX_KEYS / 2 + 1)] = node->keys[j];
        newNode->children[j - (MAX_KEYS / 2 + 1)] = node->children[j];
        node->keys[j] = 0;
        node->children[j] = NULL;
    }

    node->numKeys = MAX_KEYS / 2;

    // Insert the midKey into the parent node
    if (node == tree->root) {
        BPlusNode *newRoot = createNode(false);
        newRoot->keys[0] = midKey;
        newRoot->children[0] = node;
        newRoot->children[1] = newNode;
        newRoot->numKeys = 1;
        tree->root = newRoot;
    } else {
        // Parent node splitting logic (omitted for brevity)
    }
}

// Function to insert a key into a non-full node
void insertNonFull(BPlusTree *tree, BPlusNode *node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;

        if (node->children[i]->numKeys == MAX_KEYS) {
            splitNode(tree, node, i);
            if (node->keys[i] < key) {
                i++;
            }
        }
        insertNonFull(tree, node->children[i], key);
    }
}

// Function to insert a key into the B+ Tree
void insert(BPlusTree *tree, int key) {
    BPlusNode *root = tree->root;

    if (root->numKeys == MAX_KEYS) {
        BPlusNode *newRoot = createNode(false);
        newRoot->children[0] = root;
        splitNode(tree, newRoot, 0);
        tree->root = newRoot;
    }

    insertNonFull(tree, root, key);
}

// Function to search for a key in the B+ Tree
BPlusNode* search(BPlusTree *tree, int key) {
    BPlusNode *node = tree->root;
    while (node != NULL) {
        int i = 0;
        while (i < node->numKeys && key >= node->keys[i]) {
            if (key == node->keys[i]) {
                return node;
            }
            i++;
        }

        if (node->isLeaf) {
            return NULL;  // Key not found
        }

        node = node->children[i];
    }
    return NULL;
}

// Function to print the B+ Tree (for debugging)
void printTree(BPlusNode *node, int level) {
    if (node != NULL) {
        printf("Level %d: ", level);
        for (int i = 0; i < node->numKeys; i++) {
            printf("%d ", node->keys[i]);
        }
        printf("\n");

        if (!node->isLeaf) {
            for (int i = 0; i <= node->numKeys; i++) {
                printTree(node->children[i], level + 1);
            }
        }
    }
}

// Example usage
int main() {
    BPlusTree *tree = (BPlusTree*)malloc(sizeof(BPlusTree));
    tree->root = createNode(true);  // Create an empty root node (leaf)

    // Insert some values into the B+ Tree
    int values[] = {10, 20, 5, 6, 15, 30, 25, 40};
    for (int i = 0; i < 8; i++) {
        insert(tree, values[i]);
    }

    // Print the tree structure
    printf("B+ Tree after insertions:\n");
    printTree(tree->root, 0);

    // Search for a key
    int searchKey = 15;
    BPlusNode *result = search(tree, searchKey);
    if (result != NULL) {
        printf("Found key %d\n", searchKey);
    } else {
        printf("Key %d not found\n", searchKey);
    }

    return 0;
}
