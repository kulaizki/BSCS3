#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int *keys;           // Array to store keys
    struct Node **children;  // Array of child pointers
    int numKeys;         // Number of keys in the node
    int isLeaf;          // Flag to check if the node is a leaf
} Node;

// Function to create a new node
Node* createNode(int isLeaf) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys = (int*)malloc(sizeof(int) * 2);  // Max 2 keys per node
    newNode->children = (Node**)malloc(sizeof(Node*) * 3); // Max 3 children per node
    newNode->numKeys = 0;
    newNode->isLeaf = isLeaf;
    return newNode;
}

// Function to insert a key into a non-full node
void insertNonFull(Node* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // Find the position to insert the key
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find the child to insert the key
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;

        Node* child = node->children[i];

        if (child->numKeys == 2) {
            // Split the child if it is full
            splitChild(node, i, child);
            if (node->keys[i] < key) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Function to split a child node
void splitChild(Node* parent, int i, Node* child) {
    Node* newChild = createNode(child->isLeaf);
    parent->children[i + 1] = newChild;

    // Move the second key to the parent node
    parent->keys[i] = child->keys[1];
    parent->numKeys++;

    // Move the second key and third key of the child to the new child
    newChild->keys[0] = child->keys[2];
    newChild->numKeys = 1;

    // If child is not a leaf, move the third child to the new child
    if (!child->isLeaf) {
        newChild->children[0] = child->children[2];
        newChild->children[1] = child->children[3];
    }

    // Update the number of keys in the original child
    child->numKeys = 1;
}

// Function to insert a key into the 2-3 tree
void insert(Node** root, int key) {
    Node* r = *root;

    if (r->numKeys == 2) {
        // If the root is full, create a new root
        Node* newRoot = createNode(0);
        newRoot->children[0] = r;
        *root = newRoot;
        splitChild(newRoot, 0, r);
        insertNonFull(newRoot, key);
    } else {
        insertNonFull(r, key);
    }
}

// Function to print the tree (for debugging)
void printTree(Node* root, int level) {
    if (root != NULL) {
        printf("Level %d: ", level);
        for (int i = 0; i < root->numKeys; i++) {
            printf("%d ", root->keys[i]);
        }
        printf("\n");

        if (!root->isLeaf) {
            for (int i = 0; i <= root->numKeys; i++) {
                printTree(root->children[i], level + 1);
            }
        }
    }
}

// Function to free the memory of the tree
void freeTree(Node* root) {
    if (root != NULL) {
        for (int i = 0; i <= root->numKeys; i++) {
            freeTree(root->children[i]);
        }
        free(root->keys);
        free(root->children);
        free(root);
    }
}

// Example usage
int main() {
    Node* root = createNode(1);  // Create an empty root node

    // Insert some values into the tree
    int values[] = {10, 20, 5, 6, 15, 30, 25, 40};
    for (int i = 0; i < 8; i++) {
        insert(&root, values[i]);
    }

    // Print the tree structure
    printf("2-3 Tree after insertions:\n");
    printTree(root, 0);

    // Free the tree
    freeTree(root);

    return 0;
}
