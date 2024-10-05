#include "util.c"

void strandSort(int a[], int n, int res[], int* resN);
void merge(int res[], int* resN, int subSeq[], int subSeqN);

int main() {

    int a[SIZE] = {8, 1, 4, 3, 2, 7, 7, 1};
    int res[SIZE] = {0};  // Array to hold the sorted result
    int resN = 0;

    strandSort(a, SIZE, res, &resN);
    displayArray(res, resN);
}

void strandSort(int a[], int n, int res[], int* resN) {
    int subSeq[SIZE];  // To hold the strand
    int subSeqN = 0;

    while (n > 0) {
        subSeq[0] = a[0];
        subSeqN = 1;

        // Build a subsequence that is sorted
        for (int x = 1; x < n; x++) {
            if (a[x] >= subSeq[subSeqN - 1]) {
                subSeq[subSeqN++] = a[x];
            }
        }

        // Remove the elements of the subsequence from the array
        int newN = 0;
        for (int x = 0; x < n; x++) {
            if (a[x] != subSeq[newN]) {
                a[newN++] = a[x];
            }
        }

        // Merge the subsequence into the result array
        merge(res, resN, subSeq, subSeqN);

        n = newN;  // Update the size of the array
    }
}

void merge(int res[], int* resN, int subSeq[], int subSeqN) {
    int merged[SIZE];
    int x = 0, y = 0, z = 0;

    // Merge res[] and subSeq[]
    while (x < *resN && y < subSeqN) {
        if (res[x] <= subSeq[y]) {
            merged[z++] = res[x++];
        } else {
            merged[z++] = subSeq[y++];
        }
    }

    // Copy the remaining elements of res[], if any
    while (x < *resN) {
        merged[z++] = res[x++];
    }

    // Copy the remaining elements of subSeq[], if any
    while (y < subSeqN) {
        merged[z++] = subSeq[y++];
    }

    // Copy the merged array back to res[]
    for (x = 0; x < z; x++) {
        res[x] = merged[x];
    }

    *resN = z;  // Update the size of the result array
}
