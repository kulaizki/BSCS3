#include "util.c"

void sort(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};

    sort(a, SIZE);
    displayArray(a, SIZE);
}

void sort(int a[], int n) {

    int x, y;

    for (x = 0; x < n; ++x) {
        int swapped = 0;
        for (y = 0; y < n - x - 1; ++y) {
            if (a[y] > a[y + 1]) {
                int temp = a[y];
                a[y] = a[y + 1];
                a[y + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}