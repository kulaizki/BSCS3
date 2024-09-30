#include <stdio.h>
#include <limits.h>  

#define SIZE 8

void tournamentSort(int a[], int n);
void buildTournamentTree(int tree[], int a[], int n);
void adjustTournamentTree(int tree[], int a[], int n);
void displayArray(int a[], int n);

int main() {
    int a[SIZE] = {4, 1, 2, 3, 9, 9, 0, 3};
    
    tournamentSort(a, SIZE);
    displayArray(a, SIZE);
    
    return 0;
}

void tournamentSort(int a[], int n) {
    int tournamentTree[2 * n - 1];
    
    // Build the tournament tree
    buildTournamentTree(tournamentTree, a, n);
    
    // Repeatedly extract the winner and adjust the tree
    for (int i = 0; i < n; i++) {
        // The root of the tree is the smallest element
        a[i] = tournamentTree[0];
        
        // Replace the root with a "max" value (or INF)
        for (int j = 0; j < n; j++) {
            if (tournamentTree[n - 1 + j] == a[i]) {
                tournamentTree[n - 1 + j] = INT_MAX;  // Mark as removed
                break;
            }
        }
        
        // Adjust the tournament tree to find the next smallest element
        adjustTournamentTree(tournamentTree, a, n);
    }
}

void buildTournamentTree(int tree[], int a[], int n) {
    // Initialize leaf nodes with the array elements
    for (int i = 0; i < n; i++) {
        tree[n - 1 + i] = a[i];
    }
    
    // Build the internal nodes (winners of comparisons)
    for (int i = n - 2; i >= 0; i--) {
        tree[i] = (tree[2 * i + 1] < tree[2 * i + 2]) ? tree[2 * i + 1] : tree[2 * i + 2];
    }
}

void adjustTournamentTree(int tree[], int a[], int n) {
    // Adjust the tree starting from the leaf nodes up to the root
    int idx = 0;
    for (int i = (n - 2); i >= 0; i--) {
        tree[i] = (tree[2 * i + 1] < tree[2 * i + 2]) ? tree[2 * i + 1] : tree[2 * i + 2];
    }
}

void displayArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
