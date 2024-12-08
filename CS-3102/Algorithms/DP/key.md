## Key Concepts:
- **Optimal Substructure**: The problem can be solved by combining solutions of smaller subproblems.
- **Overlapping Subproblems**: The problem can be broken down into subproblems which are solved multiple times.
- **Memoization**: Top-down approach where results of subproblems are stored (usually in a table) to avoid recalculating.
- **Tabulation**: Bottom-up approach where subproblem solutions are computed iteratively and stored in a table.

## DP Table:
- A **DP table** is a 2D or 1D array used to store the results of subproblems.
- It is used to track intermediate results to avoid recalculating them.

### Example of DP Table (for 0/1 Knapsack Problem):
| Items \ Weight | 0  | 1  | 2  | 3  | 4  | 5  | ... |
|----------------|----|----|----|----|----|----|-----|
| 1              | 0  | 0  | 60 | 60 | 60 | 60 | ... |
| 2              | 0  | 0  | 60 | 100| 100| 160| ... |
| 3              | 0  | 0  | 60 | 100| 120| 160| ... |

### Common DP Problems:
1. **Longest Common Subsequence (LCS)**:
   - Finds the longest subsequence common to two sequences.
   - **Time Complexity**: O(m * n), where m and n are the lengths of the two sequences.

2. **0/1 Knapsack Problem**:
   - Finds the maximum value that can be obtained in a knapsack with a weight limit.
   - **Time Complexity**: O(n * W), where n is the number of items and W is the knapsack capacity.

3. **Fibonacci Sequence**:
   - A simple problem to demonstrate DP, where the nth term is the sum of the two preceding terms.
   - **Time Complexity**: O(n) with memoization or tabulation.

4. **Matrix Chain Multiplication**:
   - Determines the optimal way to multiply a sequence of matrices to minimize the number of scalar multiplications.

## Key Steps in DP:
1. **Define the State**: Express the problem in terms of smaller subproblems (e.g., subproblem results stored in `dp[i][j]`).
2. **Recurrence Relation**: Find how the solution to a subproblem relates to other subproblems.
3. **Base Case**: Initialize base cases that can be solved trivially (e.g., `dp[0][0]` = 0).
4. **Build the Solution**: Use a DP table to solve smaller subproblems and build up to the final solution.

## Important Properties:
- **Space Complexity**: Depending on the problem, can be optimized using 1D arrays or other memory-saving techniques.
- **Time Complexity**: Typically polynomial in nature (e.g., O(n * W) for knapsack).

## Types of DP:
- **Top-Down (Memoization)**: Start with the full problem and break it down, solving subproblems recursively and caching results.
- **Bottom-Up (Tabulation)**: Start from the smallest subproblems and build up to solve the larger problem.

## Summary:
Dynamic programming is essential for optimization problems, where breaking down a problem into overlapping subproblems and using previously computed results can significantly reduce the computation time.