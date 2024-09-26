#include "util.c"

#define SIZE 8

void combSort(int a[], int n);

int main() {

    int a[SIZE] = {8, 1, 4, 3, 2, 7, 7, 1};
    
    combSort(a, SIZE);
    displayArray(a, SIZE);
}

void combSort(int a[], int n) {
    int gap = n;
    int swapped = 1;
    while (gap > 1 || swapped) {
        gap = (int)(gap / 1.3);
        if (gap < 1) gap = 1;
        swapped = 0;
        int x;
        for (int x = 0; x + gap < n; ++x) {
            if (a[x] > a[x + gap]) {
                int temp = a[x];
                a[x] = a[x + gap];
                a[x + gap] = temp;
                swapped = 1;
            }
        }
    }
}