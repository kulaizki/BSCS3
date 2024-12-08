#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to find the longest common subsequence
int LCS(char *X, char *Y, int m, int n) {
    int dp[MAX][MAX];  // dp array to store lengths of LCS

    // Build the dp table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // If either string is empty, LCS is 0
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Characters match, extend the LCS
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  // Take the max
            }
        }
    }

    // The value at dp[m][n] contains the length of LCS
    return dp[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of Longest Common Subsequence: %d\n", LCS(X, Y, m, n));

    return 0;
}