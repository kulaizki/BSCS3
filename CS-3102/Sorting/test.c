#include "util.c"

void heapify(int a[], int n, int x);
void quickSort(int a[], int l, int h);
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);
void sort(int a[], int n);
int *countingSort(int a[], int n);
void displayArray(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};
    
    // quickSort(a, 0, SIZE - 1);
    // sort(a, SIZE);
    // displayArray(a, SIZE);

    // int *sorted = countingSort(a, SIZE);
    // displayArray(sorted, SIZE);

    mergeSort(a, 0, SIZE - 1);
    displayArray(a, SIZE);
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n1 * sizeof(int));
}

