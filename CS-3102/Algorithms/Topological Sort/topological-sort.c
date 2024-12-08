#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Adjacency list representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize a graph
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Recursive function to perform DFS
void topologicalSortUtil(Graph* graph, int v, int* stack, int* index) {
    graph->visited[v] = 1;

    // Recur for all the vertices adjacent to this vertex
    Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            topologicalSortUtil(graph, adjVertex, stack, index);
        }
        temp = temp->next;
    }

    // Push current vertex to stack
    stack[*index] = v;
    (*index)++;
}

// Function to perform Topological Sort
void topologicalSort(Graph* graph) {
    int stack[MAX_VERTICES];
    int index = 0;

    // Perform DFS from each unvisited vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            topologicalSortUtil(graph, i, stack, &index);
        }
    }

    // Print topologically sorted order
    printf("Topological Sort: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    Graph graph;
    initGraph(&graph, 6); // 6 vertices (0 to 5)

    // Adding edges to the graph
    addEdge(&graph, 5, 2);
    addEdge(&graph, 5, 0);
    addEdge(&graph, 4, 0);
    addEdge(&graph, 4, 1);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 1);

    // Perform topological sort
    topologicalSort(&graph);

    return 0;
}