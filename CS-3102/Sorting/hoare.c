#include "util.c"

void quickSort(int a[], int l, int h);

int main() {

    int a[SIZE] = {6, 9, 1, 2, 5, 8, 2, 0};

    quickSort(a, 0, SIZE - 1);
    displayArray(a, SIZE);
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int pivot = a[l];  
        int x = l - 1;
        int y = h + 1;

        while (1) {
            do { ++x; } while (a[x] < pivot);
            do { --y; } while (a[y] > pivot);

            if (x >= y) break;

            int temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }

        quickSort(a, l, y);     // Sort the left side of the partition
        quickSort(a, y + 1, h); // Sort the right side of the partition
    }
}
