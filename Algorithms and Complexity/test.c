#include "util.c"

void sort(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};

    sort(a, SIZE);
    displayArray(a, SIZE);
}

void sort(int a[], int n) {
    
    int gap, x, y;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (x = gap; x < n; ++x) {
            int key = a[x];
            for (y = x; y >= gap && a[y - gap] > key; y -= gap) {
                a[y] = a[y - gap];
            }
            a[y] = key;
        }
    }
}