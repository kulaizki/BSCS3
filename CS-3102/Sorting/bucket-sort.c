#include "util.c"

void bucketSort(float a[], int n);

int main() {

    float a[SIZE] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12};
    
    bucketSort(a, SIZE);
    displayArrayF(a, SIZE);  
}

void bucketSort(float a[], int n) {
    // Create n empty buckets
    float b[SIZE][SIZE];   // Buckets
    int bN[SIZE] = {0};    // Bucket sizes

    // Put elements into different buckets
    for (int x = 0; x < n; ++x) {
        int bIdx = n * a[x];  // Calculate bucket index
        b[bIdx][bN[bIdx]++] = a[x];  // Add to bucket and increment bucket size
    }

    // Sort individual buckets using insertion sort
    for (int x = 0; x < n; x++) {
        int subSeqN = bN[x];  // Number of elements in current bucket
        float* subSeq = b[x]; // Current bucket 

        // Insertion sort for individual bucket 
        for (int y = 1; y < subSeqN; ++y) {
            float key = subSeq[y];
            int z = y - 1;

            while (z >= 0 && subSeq[z] > key) {
                subSeq[z + 1] = subSeq[z];
                z--;
            }
            subSeq[z + 1] = key;
        }
    }

    // Concatenate all buckets into result array
    int z = 0;  // Index for original array
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < bN[x]; ++y, ++z) {
            a[z++] = b[x][y];  // Copy sorted elements back to a[]
        }
    }
}
