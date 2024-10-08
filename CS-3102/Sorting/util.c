#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

typedef struct Node {
    int data;
    struct Node *link;
} *LIST;

void insert(LIST *list, int value);
void bucketSort(int a[], int n);
void quickSort(int a[], int l, int h);
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);
void sort(int a[], int n);
int *countingSort(int a[], int n);
void displayArray(int a[], int n);

#define SIZE 8

void displayArray(int a[], int n) {
    int x;
    for (x = 0; x < n; ++x) {
        printf("%d ", a[x]);
    }
    printf("\n");
}