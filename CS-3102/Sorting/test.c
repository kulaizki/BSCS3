#include "util.c"

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};
    
    // quickSort(a, 0, SIZE - 1);
    // sort(a, SIZE);

    // int *sorted = countingSort(a, SIZE);
    // displayArray(sorted, SIZE);

    // mergeSort(a, 0, SIZE - 1);
    bucketSort(a, SIZE);
    displayArray(a, SIZE);
}

void insert(LIST *L, int value) {
    LIST *trav;
    for (trav = L; *trav != NULL && (*trav)->data < value; trav = &(*trav)->link) {}
    LIST newNode = (LIST)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->link = *trav;  
        *trav = newNode;        
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
        LIST curr = buckets[x];
        while (curr != NULL) {
            a[idx++] = curr->data;
            LIST temp = curr;
            curr = curr->link;
            free(temp);
        }
    }
}