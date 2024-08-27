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

    int* count = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    int* sorted = (int *)malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; --i){
        sorted[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    return sorted;
}

void display(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
