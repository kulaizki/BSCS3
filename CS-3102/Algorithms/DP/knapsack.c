#include <stdio.h>

#define MAX 100

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];  // dp table to store the maximum value at each weight

    // Build the dp table in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or weight 0, the value is 0
            } else if (wt[i - 1] <= w) {
                dp[i][w] = (val[i - 1] + dp[i - 1][w - wt[i - 1]] > dp[i - 1][w]) ? 
                            val[i - 1] + dp[i - 1][w - wt[i - 1]] : dp[i - 1][w];  // Include or exclude the item
            } else {
                dp[i][w] = dp[i - 1][w];  // Exclude the item if weight exceeds
            }
        }
    }

    // The value at dp[n][W] contains the maximum value that can be obtained
    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack: %d\n", knapsack(W, wt, val, n));

    return 0;
}