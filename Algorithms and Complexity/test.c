#include "util.c"

void sort(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};

    sort(a, SIZE);
    displayArray(a, SIZE);
}

void sort(int a[], int n) {

    int gap = n;
    int swapped = 1;

    while (gap > 1 || swapped) {
        gap = (int)(gap / 1.3);
        if (gap < 1) gap = 1;
        swapped = 0;

        int x;
        for (x = 0; x + gap < n; ++x) {
            if (a[x] > a[x + gap]) {
                int temp = a[x];
                a[x] = a[x + gap];
                a[x + gap] = temp;
                swapped = 1;
            }
        }
    }
}
