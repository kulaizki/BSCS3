#include "util.c"

void selectionSort(int a[], int n);

int main() {

    int a[SIZE] = {6, 9, 1, 2, 5, 8, 2, 0};

    selectionSort(a, SIZE);
    displayArray(a, SIZE);
}

void selectionSort(int a[], int n) {

    int x, y;

    for (x = 0; x < n; ++x) {
        int min = x;
        for (y = x + 1; y < n; ++y) {
            if (a[y] < a[min]) {
                min = y;
            }
        }
        if (min != x) {
            int temp = a[x];
            a[x] = a[min];
            a[min] = temp;
        }
    }
}