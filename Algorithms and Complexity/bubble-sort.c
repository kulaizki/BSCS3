#include <stdio.h>

#define SIZE 8

void bubbleSort(int a[], int n);
void displayArray(int a[], int n);

int main() {

    int a[SIZE] = {4, 1, 3, 4, 9, 0, 1, 2};

    bubbleSort(a, SIZE);
    displayArray(a, SIZE);
}

void bubbleSort(int a[], int n) {
    int x, y;
    for (x = 0; x < n; ++x) {
        for (y = 0; y < n - x - 1; ++y) {
            if (a[y] > a[y + 1]) {
                int temp = a[y];
                a[y] = a[y + 1];
                a[y + 1] = temp;
            }
        }
    }
}

void displayArray(int a[], int n) {
    int x;
    for (x = 0; x < n; ++x) {
        printf("%d ", a[x]);
    }
    printf("\n");
}