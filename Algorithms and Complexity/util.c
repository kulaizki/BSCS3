#include <stdio.h>

void displayArray(int a[], int n) {
    int x;
    for (x = 0; x < n; ++x) {
        printf("%d ", a[x]);
    }
    printf("\n");
}