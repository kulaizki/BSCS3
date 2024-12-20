#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a connected, directed and weighted graph
struct Graph {
    int V, E; // V-> Number of vertices, E-> Number of edges
    struct Edge* edge; // Array of edges
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// Function to implement the Bellman-Ford algorithm
void bellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    
    // Distance from source to itself is always 0
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles.
    for (int j = 0; j < E; j++) {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight = graph->edge[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print all distances
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Main function to test the Bellman-Ford algorithm implementation
int main() {
    int V = 5; // Number of vertices in the graph
    int E = 8; // Number of edges in the graph

    struct Graph* graph = createGraph(V, E);

    // Adding edges to the graph
    graph->edge[0].src = 0; graph->edge[0].dest = 1; graph->edge[0].weight = -1;
    graph->edge[1].src = 0; graph->edge[1].dest = 2; graph->edge[1].weight = 4;
    graph->edge[2].src = 1; graph->edge[2].dest = 2; graph->edge[2].weight = 3;
    graph->edge[3].src = 1; graph->edge[3].dest = 3; graph->edge[3].weight = 2;
    graph->edge[4].src = 1; graph->edge[4].dest = 4; graph->edge[4].weight = 2;
    graph->edge[5].src = 3; graph->edge[5].dest = 2; graph->edge[5].weight = 5;
    graph->edge[6].src = 3; graph->edge[6].dest = 1; graph->edge[6].weight = 1;
    graph->edge[7].src = 4; graph->edge[7].dest = 3; graph->edge[7].weight = -3;

    bellmanFord(graph, 0); // Source vertex is set to 0

    return 0;
}