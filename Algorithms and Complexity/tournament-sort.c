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

void tournamentSort(int a[], int n){

    int heapN = 2 * n - 1;
    int winnerTree[heapN];
    int startNdx = heapN - 1;
    int x, y;
    int P, LC, RC;

    for(x = n - 1, y = startNdx; x > -1;){
        winnerTree[y--] = a[x--];
    }

    for(x = 0; x < n; x++){
        for(P = (startNdx - 1) / 2; P > -1; ){
            LC = 2 * P + 1;
            RC = LC + 1;

            LC = (LC < heapN - n) ?  winnerTree[LC] : LC;
            RC = (RC < heapN- n) ?  winnerTree[RC] : RC;

            winnerTree[P] = (winnerTree[LC] < winnerTree[RC])? LC : RC;
            P = (x > 0 && P > 0) ? (P - 1) / 2 : P - 1;
        }

        startNdx = winnerTree[0];
        a[x] = winnerTree[startNdx];
        winnerTree[startNdx] = INT_MAX;
  }
}

void displayArray(int a[], int n) {
    for (int x = 0; x < n; x++) {
        printf("%d ", a[x]);
    }
    printf("\n");
}
