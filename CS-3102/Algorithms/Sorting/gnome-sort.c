#include "util.c"

void gnomeSort(int a[], int n);

int main() {

    int a[SIZE] = {8, 1, 4, 3, 2, 7, 7, 1};
    
    gnomeSort(a, SIZE);
    displayArray(a, SIZE);
}

void gnomeSort(int a[], int n) {

    int x = 0;

    while (x < n) {
        if (x == 0 || a[x] >= a[x - 1])
            x++;
        else {
            int temp = a[x];
            a[x] = a[x - 1];
            a[x- 1] = temp;
            x--;
        }
    }
}