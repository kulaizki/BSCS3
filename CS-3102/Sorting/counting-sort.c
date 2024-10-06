#include <stdio.h>
#include <stdlib.h>

int* countingSort(int a[], int n);
void display(int a[], int n);

int main() {

    int a[10] = {3, 2, 1, 4, 8, 21, 0, 1, 1, 4};
    printf("Initial: ");
    display(a, 10);

    int* sorted = countingSort(a, 10);
    printf("Sorted: ");
    display(sorted, 10);
}

int* countingSort(int a[], int n) {

    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > max) max = a[i];
    }

    int *freq = (int *)calloc(max + 1, sizeof(int));

    // count array
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
    }

    // prefix sum array
    for (int i = 1; i <= max; ++i) {
        freq[i] += freq[i - 1];
    }

    // sorted array
    int *res = (int *)malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; --i){
        res[freq[a[i]] - 1] = a[i];
        freq[a[i]]--;
    }

    free(freq);

    return res;
}

void display(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
