#include "util.c"

void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);

int main() {

    int a[SIZE] = {8, 1, 4, 3, 2, 7, 7, 1};
    
    mergeSort(a, 0, SIZE - 1);
    displayArray(a, SIZE);
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays
    for (int x = 0; x < n1; x++)
        L[x] = a[l + x];
    for (int y = 0; y < n2; y++)
        R[y] = a[m + 1 + y];

    // Merge the temp arrays back into a[]
    int x = 0, y = 0, z;
    for (z = l; x < n1 && y < n2; z++) {
        if (L[x] <= R[y]) {
            a[z] = L[x];
            x++;
        } else {
            a[z] = R[y];
            y++;
        }
    }

    // Copy the remaining elements of L[], if any
    for (; x < n1; x++, z++) {
        a[z] = L[x];
    }

    // Copy the remaining elements of R[], if any
    for (; y < n2; y++, z++) {
        a[z] = R[y];
    }

    free(L);
    free(R);
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        // Merge the sorted halves
        merge(a, l, m, r);
    }
}