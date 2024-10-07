#include "util.c"

int getMax(int a[], int n);
void countingSort(int a[], int n, int exp);
void radixSort(int a[], int n);

int main() {

    int a[SIZE] = {8, 1, 4, 3, 2, 7, 7, 1};
    
    radixSort(a, SIZE);
    displayArray(a, SIZE);
}

int getMax(int a[], int n) {
    int mx = a[0];
    for (int x = 1; x < n; x++) {
        if (a[x] > mx) {
            mx = a[x];
        }
    }
    return mx;
}

void countingSort(int a[], int n, int exp) {
    int res[n]; // sorted
    int freq[10] = {0}; // digit count 

    // Store the count of occurrences of each digit
    for (int x = 0; x < n; x++) {
        freq[(a[x] / exp) % 10]++;
    }

    // Change count so that it contains the actual position of the digit in res[]
    for (int x = 1; x < 10; x++) {
        freq[x] += freq[x - 1];
    }

    // Build the sorted array
    for (int x = n - 1; x >= 0; x--) {
        res[freq[(a[x] / exp) % 10] - 1] = a[x];
        freq[(a[x] / exp) % 10]--;
    }

    // Copy the sorted array to a[]
    for (int x = 0; x < n; x++) {
        a[x] = res[x];
    }
}

void radixSort(int a[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(a, n);

    // Perform counting sort for each digit, starting with the least significant digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(a, n, exp);
    }
}
