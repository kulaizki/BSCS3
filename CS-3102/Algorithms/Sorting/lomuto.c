#include "util.c"

void quickSort(int a[], int l, int h);

int main() {

    int a[SIZE] = {6, 9, 1, 2, 5, 8, 2, 0};

    quickSort(a, 0, SIZE - 1);
    displayArray(a, SIZE);
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int pivot = a[h];  
        int x = l - 1;
        for (int y = l; y < h; y++) {
            if (a[y] <= pivot) {
                x++;
                int temp = a[x];
                a[x] = a[y];
                a[y] = temp;
            }
        }

        int temp = a[x + 1];
        a[x + 1] = a[h];
        a[h] = temp;

        quickSort(a, l, x);
        quickSort(a, x + 2, h);
    }
}