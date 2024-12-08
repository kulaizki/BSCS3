#include <stdio.h>
#define INF 99999  // Represents no edge between vertices

void warshall(int graph[][4], int V) {
    // Create a matrix to store the reachability information
    int reach[V][V];

    // Initialize the reachability matrix as the original graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    // Apply Warshall's algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If a path exists from i to k and from k to j, set reach[i][j] to 1 (path exists)
                if (reach[i][k] != INF && reach[k][j] != INF) {
                    reach[i][j] = 1;
                }
            }
        }
    }

    // Print the transitive closure matrix
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (reach[i][j] == INF) {
                printf("0 ");
            } else {
                printf("1 ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Adjacency matrix for a directed graph
    int graph[4][4] = {
        {0, 1, INF, INF},
        {INF, 0, 1, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    
    int V = 4; // Number of vertices

    // Run Warshall's algorithm
    warshall(graph, V);

    return 0;
}