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
    int max = a[0];
    for (int x = 1; x < n; x++) {
        if (a[x] > max) {
            max = a[x];
        }
    }
    return max;
}

void countingSort(int a[], int n, int exp) {
    int output[n]; // Output array to store the sorted values
    int count[10] = {0}; // Count array for the digits

    // Store the count of occurrences of each digit
    for (int x = 0; x < n; x++) {
        count[(a[x] / exp) % 10]++;
    }

    // Change count so that it contains the actual position of the digit in output[]
    for (int x = 1; x < 10; x++) {
        count[x] += count[x - 1];
    }

    // Build the output array
    for (int x = n - 1; x >= 0; x--) {
        output[count[(a[x] / exp) % 10] - 1] = a[x];
        count[(a[x] / exp) % 10]--;
    }

    // Copy the output array to a[], so that a[] now contains sorted numbers
    for (int x = 0; x < n; x++) {
        a[x] = output[x];
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
