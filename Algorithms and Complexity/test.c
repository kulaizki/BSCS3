#include "util.c"

void heapify(int a[], int n, int x);
void sort(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};

    sort(a, SIZE);
    displayArray(a, SIZE);
}

void heapify(int a[], int n, int x) {
    int largest = x;
    int l = 2 * x + 1;
    int r = 2 * x + 2;

    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != x) {
        int temp = a[x];
        a[x] = a[largest];
        a[largest] = temp;
        heapify(a, n, x);
    }
}

void sort(int a[], int n) {
    int x;
    for (x = n / 2 - 1; x >= 0; --x) {
        heapify(a, n, x);
    }

    for (x = n - 1; x > 0; --x) {
        int temp = a[0];
        a[0] = a[x];
        a[x] = temp;
        heapify(a, x, 0);
    }
}
