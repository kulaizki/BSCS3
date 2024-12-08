#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_LEVEL 16
#define P 0.5

// Skiplist node structure
typedef struct SkiplistNode {
    int key;
    void* value;
    struct SkiplistNode** forward;
} SkiplistNode;

// Skiplist structure
typedef struct {
    SkiplistNode* header;
    int level;
} Skiplist;

// Random level generation function
int randomLevel() {
    int lvl = 1;
    while ((rand() / (double)RAND_MAX) < P && lvl < MAX_LEVEL) {
        lvl++;
    }
    return lvl;
}

// Create a new skiplist node
SkiplistNode* createNode(int key, void* value, int level) {
    SkiplistNode* node = (SkiplistNode*)malloc(sizeof(SkiplistNode));
    node->key = key;
    node->value = value;
    
    // Allocate memory for forward pointers
    node->forward = (SkiplistNode**)malloc(sizeof(SkiplistNode*) * (level + 1));
    
    // Initialize forward pointers to NULL
    for (int i = 0; i <= level; i++) {
        node->forward[i] = NULL;
    }
    
    return node;
}

// Initialize a new skiplist
Skiplist* createSkiplist() {
    // Seed random number generator
    srand(time(NULL));
    
    Skiplist* list = (Skiplist*)malloc(sizeof(Skiplist));
    list->level = 0;
    
    // Create header node with maximum possible key
    list->header = createNode(INT_MAX, NULL, MAX_LEVEL);
    
    return list;
}

// Insert a key-value pair into the skiplist
void skiplistInsert(Skiplist* list, int key, void* value) {
    // Array to keep track of nodes to update
    SkiplistNode* update[MAX_LEVEL + 1];
    SkiplistNode* current = list->header;
    
    // Start from the highest level and move down
    for (int i = list->level; i >= 0; i--) {
        // Move forward while next node's key is less than target key
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    // Move to the node that might be just before the insertion point
    current = current->forward[0];
    
    // If key already exists, update the value (or handle as needed)
    if (current && current->key == key) {
        current->value = value;
        return;
    }
    
    // Generate random level for new node
    int newLevel = randomLevel();
    
    // If new level is higher than current list level, update header
    if (newLevel > list->level) {
        for (int i = list->level + 1; i <= newLevel; i++) {
            update[i] = list->header;
        }
        list->level = newLevel;
    }
    
    // Create new node
    SkiplistNode* newNode = createNode(key, value, newLevel);
    
    // Update forward pointers
    for (int i = 0; i <= newLevel; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
}

// Delete a key from the skiplist
int skiplistDelete(Skiplist* list, int key) {
    // Array to keep track of nodes to update
    SkiplistNode* update[MAX_LEVEL + 1];
    SkiplistNode* current = list->header;
    
    // Start from the highest level and move down
    for (int i = list->level; i >= 0; i--) {
        // Move forward while next node's key is less than target key
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    // Move to the potential node to delete
    current = current->forward[0];
    
    // Check if key exists
    if (current && current->key == key) {
        // Update forward pointers to skip the node to be deleted
        for (int i = 0; i <= list->level; i++) {
            // If update pointer's forward is not the node to delete, break
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }
        
        // Free the node
        free(current->forward);
        free(current);
        
        // Adjust list level if necessary
        while (list->level > 0 && 
               list->header->forward[list->level] == NULL) {
            list->level--;
        }
        
        return 1; // Deletion successful
    }
    
    return 0; // Key not found
}

// Print the skiplist (for debugging)
void printSkiplist(Skiplist* list) {
    for (int i = list->level; i >= 0; i--) {
        printf("Level %d: ", i);
        SkiplistNode* current = list->header->forward[i];
        while (current && current->key != INT_MAX) {
            printf("%d ", current->key);
            current = current->forward[i];
        }
        printf("\n");
    }
}

// Free the entire skiplist
void freeSkiplist(Skiplist* list) {
    SkiplistNode* current = list->header->forward[0];
    
    // Free each node
    while (current && current->key != INT_MAX) {
        SkiplistNode* temp = current;
        current = current->forward[0];
        
        free(temp->forward);
        free(temp);
    }
    
    // Free header and list
    free(list->header->forward);
    free(list->header);
    free(list);
}

// Example usage
int main() {
    Skiplist* list = createSkiplist();
    
    // Insert some values
    int values[] = {3, 6, 9, 2, 11, 1, 4};
    for (int i = 0; i < 7; i++) {
        skiplistInsert(list, values[i], NULL);
    }
    
    printf("Skiplist after insertions:\n");
    printSkiplist(list);
    
    // Delete some values
    printf("\nDeleting 6:\n");
    skiplistDelete(list, 6);
    printSkiplist(list);
    
    printf("\nDeleting 11:\n");
    skiplistDelete(list, 11);
    printSkiplist(list);
    
    // Free the skiplist
    freeSkiplist(list);
    
    return 0;
}