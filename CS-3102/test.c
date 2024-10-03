#include <stdio.h>
#include <limits.h>  

#define SIZE 8

void heapify(int a[], int n, int x);
void sort(int a[], int n);
void displayArray(int a[], int n);

int main() {
    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};
    
    sort(a, SIZE);
    displayArray(a, SIZE);
    
    return 0;
}

void sort(int a[], int n) {

    int heapN = 2 * n - 1;
    int heap[heapN];
    int startIdx = heapN - 1;
    int x, y, P, LC, RC;

    for (x = n - 1, y = startIdx; y >= 0; --x, --y) {
        heap[y] = a[x];
    }

    for (x = 0; x < n; ++x) {
        for (P = (startIdx - 1) / 2; P >= 0;) {
            LC = 2 * P + 1;
            RC = LC + 1;

            LC = (LC < heapN - n) ? heap[LC] : LC;
            RC = (RC < heapN - n) ? heap[RC] : RC;

            heap[P] = heap[LC] < heap[RC] ? LC : RC;
            P = (x > 0 && P > 0) ? (P - 1) / 2 : P - 1;
        }

        startIdx = heap[0];
        a[x] = heap[startIdx];
        heap[startIdx] = INT_MAX;
    }
}

void displayArray(int a[], int n) {
    for (int x = 0; x < n; x++) {
        printf("%d ", a[x]);
    }
    printf("\n");
}
