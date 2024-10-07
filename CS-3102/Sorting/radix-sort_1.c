#include "util.c"

void countingSort(int a[], int n, int exp);
void radixSort(int a[], int n);

int main() {

    int a[SIZE] = {8, 1, 4, 3, 2, 7, 7, 1};
    
    radixSort(a, SIZE);
    displayArray(a, SIZE);
}

void countingSort(int a[], int n, int exp) {
    int res[n]; // sorted
    int freq[10] = {0}; // digit count 

    // count of occurrences of each digit
    for (int x = 0; x < n; x++) {
        freq[(a[x] / exp) % 10]++;
    }

    // change count so that it contains the actual position of the digit in res[]
    for (int x = 1; x < 10; x++) {
        freq[x] += freq[x - 1];
    }

    // build the sorted array
    for (int x = n - 1; x >= 0; x--) {
        res[freq[(a[x] / exp) % 10] - 1] = a[x];
        freq[(a[x] / exp) % 10]--;
    }

    for (int x = 0; x < n; x++) {
        a[x] = res[x];
    }
}

void radixSort(int a[], int n) {
    int mx = a[0];
    for (int x = 0; x < n; ++x) {
        if (a[x] > mx) mx = a[x];
    }

    // counting sort for each digit, starting with the least significant digit
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        countingSort(a, n, exp);
    }
}
