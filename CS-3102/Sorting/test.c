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
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int x = 0; x < n1; ++x) {
        L[x] = a[l + x];
    }

    for (int y = 0; y < n2; ++y) {
        R[y] = a[m + 1 + y];
    }

    int x = 0, y = 0, z;
    for (z = l; x < n1 && y < n2; ++z) {
        if (L[x] <= R[y]) {
            a[z] = L[x];
            ++x;
        } else {
            a[z] = R[y];
            ++y;
        }
    }

    for (; x < n1; ++x, ++z) {
        a[z] = L[x];
    }

    for (; y < n2; ++y, ++z) {
        a[z] = R[y];
    }

    free(L);
    free(R);
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}