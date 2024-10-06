#include "util.c"

void heapify(int a[], int n, int x);
void quickSort(int a[], int l, int h);
void sort(int a[], int n);
void displayArray(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};
    
    quickSort(a, 0, SIZE - 1);
    displayArray(a, SIZE);
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int pivot = a[l];
        int x = l - 1, y = h + 1;

        while (1) {
            for (x++; a[x] < pivot; x++) {}
            for (y++; a[y] > pivot; y--) {}

            if (x >= y) break;

            int temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }

        quickSort(a, l, y);     // Sort left partition
        quickSort(a, y + 1, h); // Sort right partition
    }
}

