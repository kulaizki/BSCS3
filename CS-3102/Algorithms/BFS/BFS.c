#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure to be used in BFS
typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
        return item;
    }
}

// Graph representation using adjacency list
typedef struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph
void createGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph *g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1; // For undirected graph
}

// Function to perform BFS
void bfs(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0};  // Array to mark visited nodes
    Queue q;
    initQueue(&q);

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    Graph g;
    createGraph(&g, 6); // Create a graph with 6 vertices

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 5);

    printf("Breadth First Search starting from vertex 0:\n");
    bfs(&g, 0); // Perform BFS starting from vertex 0
    printf("\n");

    return 0;
}