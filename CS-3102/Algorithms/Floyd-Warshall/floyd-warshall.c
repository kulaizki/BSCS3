#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 4  // Number of vertices in the graph

void floydWarshall(int graph[V][V]) {
    int dist[V][V], i, j, k;

    // Initialize the distance matrix same as the input graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == 0 && i != j) {
                dist[i][j] = INF;  // No direct path
            } else {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Apply Floyd-Warshall algorithm
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 3, INF, INF},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF, 0}
    };

    // Run Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}