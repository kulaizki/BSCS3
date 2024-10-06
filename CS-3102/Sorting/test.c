#include "util.c"

void heapify(int a[], int n, int x);
void quickSort(int a[], int l, int h);
void sort(int a[], int n);
void displayArray(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};
    
    quickSort(a, 0, SIZE - 1);
    // sort(a, SIZE);
    displayArray(a, SIZE);
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int p = a[h];
        int x = l - 1;
        for (int y = l; y < h; ++y) {
            if (a[y] <= p) {
                ++x;
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