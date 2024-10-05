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
        int x, y;
        for (x = l - 1, y = l; y < h; y++) {
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

        int pi = x + 1;
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h);
    }
}