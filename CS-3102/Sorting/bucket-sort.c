#include "util.c"
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} *LIST;

void bucketSort(float a[], int n);
void insertSorted(LIST *bucket, int value);
void freeBuckets(LIST bucket[], int n);

int main()
{
    float a[SIZE] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12};
    
    bucketSort(a, SIZE);
    displayArrayF(a, SIZE);
}

void bucketSort(float a[], int n)
{
    // Create an array of linked lists (buckets)
    LIST buckets[SIZE] = {NULL};

    // Find the bucket index and insert elements into their respective buckets
    for (int x = 0; x < n; ++x)
    {
        int bIdx = n * a[x];  // Calculate bucket index (assuming values between 0 and 1)
        insertSorted(&buckets[bIdx], (int)(a[x] * 100));  // Insert into the appropriate bucket after scaling
    }

    // Concatenate all the sorted buckets back into the array
    int z = 0;
    for (int x = 0; x < n; ++x)
    {
        LIST node = buckets[x];
        while (node != NULL)
        {
            a[z++] = node->data / 100.0;  // Copy sorted elements back to array and scale down
            node = node->link;
        }
    }

    freeBuckets(buckets, n);
}

// Insert a value into the bucket (linked list) in sorted order
void insertSorted(LIST *bucket, int value)
{
    LIST newNode = (LIST)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->link = NULL;

    // If the bucket is empty or the new value is smaller than the head
    if (*bucket == NULL || (*bucket)->data >= value) {
        newNode->link = *bucket;
        *bucket = newNode;
    } else {
        LIST current = *bucket;
        while (current->link != NULL && current->link->data < value) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

void freeBuckets(LIST bucket[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        LIST node = bucket[i];
        while (node != NULL)
        {
            LIST temp = node;
            node = node->link;
            free(temp);
        }
    }
}
