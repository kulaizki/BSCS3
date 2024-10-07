#include "util.c"

#define BUCKETS 10

typedef struct Node {
    int data;
    struct Node *link;
} *LIST;

void insert(LIST *list, int value);
void bucketSort(int a[], int n);

int main() {

    int a[SIZE] = {8, 1, 4, 3, 2, 7, 7, 1};

    bucketSort(a, SIZE);
    displayArray(a, SIZE);
}

void insert(LIST *list, int value) {
    LIST newNode = (LIST)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->link = NULL;

    if (*list == NULL || (*list)->data >= value) {
        newNode->link = *list;
        *list = newNode;
    } else {
        LIST current = *list;
        while (current->link != NULL && current->link->data < value) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

void bucketSort(int a[], int n) {
    LIST buckets[BUCKETS] = {NULL};

    // Distribute the elements into buckets
    for (int x = 0; x < n; x++) {
        int index = a[x] / BUCKETS; // Assuming all elements are in range 0-99
        insert(&buckets[index], a[x]);
    }

    // Concatenate all buckets back into array
    int idx = 0;
    for (int x = 0; x < BUCKETS; x++) {
        LIST current = buckets[x];
        while (current != NULL) {
            a[idx++] = current->data;
            LIST temp = current;
            current = current->link;
            free(temp);
        }
    }
}
