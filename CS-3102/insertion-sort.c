#include "util.c"

#define SIZE 8

void insertionSort(int a[], int n);

int main() {

    int a[SIZE] = {4, 0, 2, 7, 5, 3, 5, 1};

    insertionSort(a, SIZE);
    displayArray(a, SIZE);    
}

void insertionSort(int a[], int n) {

    int x, y;
    for (x = 1; x < n; ++x) {
        int key = a[x];
        for (y = x - 1; y >= 0 && a[y] > key; --y) {
            a[y + 1] = a[y];
        }
        a[y + 1] = key;
    }
}