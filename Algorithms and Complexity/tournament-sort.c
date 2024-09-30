#include <stdio.h>
#include <limits.h>  

#define SIZE 8

void tournamentSort(int a[], int n);
void displayArray(int a[], int n);

int main() {
    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};
    
    tournamentSort(a, SIZE);
    displayArray(a, SIZE);
    
    return 0;
}

void tournamentSort(int a[], int n) {

    int tree[2 * n - 1]; // Renamed tournamentTree to tree
    int x, y;
    
    // Build the tournament tree
    for (x = 0; x < n; x++) {
        tree[n - 1 + x] = a[x]; // Initialize leaf nodes with the array elements
    }

    // Build internal nodes (winners of comparisons)
    for (x = n - 2; x >= 0; x--) {
        tree[x] = (tree[2 * x + 1] < tree[2 * x + 2]) ? tree[2 * x + 1] : tree[2 * x + 2];
    }

    // Repeatedly extract the winner and adjust the tree
    for (x = 0; x < n; x++) {
        a[x] = tree[0]; // The root of the tree is the smallest element
        
        // Replace the root with INT_MAX to mark the removal
        for (y = 0; y < n; y++) {
            if (tree[n - 1 + y] == a[x]) {
                tree[n - 1 + y] = INT_MAX; // Mark as removed
                break;
            }
        }
        
        // Adjust the tree after removal of the current smallest
        int z;
        for (z = (n - 2); z >= 0; z--) {
            tree[z] = (tree[2 * z + 1] < tree[2 * z + 2]) ? tree[2 * z + 1] : tree[2 * z + 2];
        }
    }
}

void displayArray(int a[], int n) {
    int x;
    for (x = 0; x < n; x++) {
        printf("%d ", a[x]);
    }
    printf("\n");
}
