#include "util.c"

void heapify(int a[], int n, int x);
void quickSort(int a[], int l, int h);
void sort(int a[], int n);
int *countingSort(int a[], int n);
void displayArray(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};
    
    // quickSort(a, 0, SIZE - 1);
    // sort(a, SIZE);
    // displayArray(a, SIZE);

    int *sorted = countingSort(a, SIZE);
    displayArray(sorted, SIZE);
}

