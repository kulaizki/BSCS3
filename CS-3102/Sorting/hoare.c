#include "util.c"
#include <stdio.h>

void quickSort(int a[], int l, int h);

// Utility function to visualize the array at each step
void displayArrayWithMarkers(int a[], int size, int l, int h, int pivotIndex) {
    for (int i = 0; i < size; i++) {
        if (i == pivotIndex)
            printf("[%d]* ", a[i]);  // Mark pivot
        else if (i == l)
            printf("[%d]L ", a[i]);  // Mark left boundary
        else if (i == h)
            printf("[%d]H ", a[i]);  // Mark right boundary
        else
            printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[SIZE] = {6, 9, 1, 2, 5, 8, 2, 0};

    printf("Initial array:\n");
    displayArray(a, SIZE);
    quickSort(a, 0, SIZE - 1);
    printf("Sorted array:\n");
    displayArray(a, SIZE);
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int pivot = a[l];
        int x = l - 1, y = h + 1;

        printf("\nPartitioning with pivot %d (index %d):\n", pivot, l);

        while (1) {
            for (x++; a[x] < pivot; x++) {}
            for (y--; a[y] > pivot; y--) {}

            if (x >= y) break;

            int temp = a[x];
            a[x] = a[y];
            a[y] = temp;

            printf("After swapping a[%d] and a[%d]:\n", x, y);
            displayArray(a, SIZE);  
        }

        printf("Partition complete:\n");
        displayArrayWithMarkers(a, SIZE, l, h, y);

        quickSort(a, l, y);  // Sort left partition
        quickSort(a, y + 1, h);  // Sort right partition
    }
}
