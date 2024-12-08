#include <stdio.h>
#include <stdlib.h>

#define INF 999999
#define V 5 // Number of vertices
#define E 8 // Number of edges

// Structure for an edge
typedef struct {
    int u, v, weight;
} Edge;

// Function to implement Bellman-Ford algorithm
void bellmanFord(Edge edges[], int V, int E, int source) {
    int dist[V]; // Array to store shortest distances from source
    // Initialize distances from source to all vertices as INFINITY
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[source] = 0; // Distance to source is 0

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the shortest distances from the source
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d        %d\n", i, dist[i]);
    }
}

int main() {
    // Define edges of the graph
    Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    // Run Bellman-Ford algorithm from source vertex 0
    bellmanFord(edges, V, E, 0);

    return 0;
}