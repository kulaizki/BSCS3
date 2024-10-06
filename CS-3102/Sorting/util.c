#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void displayArray(int a[], int n) {
    int x;
    for (x = 0; x < n; ++x) {
        printf("%d ", a[x]);
    }
    printf("\n");
}