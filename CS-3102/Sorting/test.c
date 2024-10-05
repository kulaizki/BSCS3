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

    int x = 0;

    while (x < n) {
        if (x == 0 || a[x] >= a[x - 1]) {
            ++x;
        } else {
            int temp = a[x];
            a[x] = a[x - 1];
            a[x - 1] = temp;
            --x;
        }
    }
}

void displayArray(int a[], int n) {
    for (int x = 0; x < n; x++) {
        printf("%d ", a[x]);
    }
    printf("\n");
}
