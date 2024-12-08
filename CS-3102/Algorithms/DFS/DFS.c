#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph representation using adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];  // Adjacency list for the graph
bool visited[MAX_VERTICES];    // Array to keep track of visited nodes

// Stack to simulate the iterative DFS
int stack[MAX_VERTICES];
int top = -1;

// Function to create a new adjacency list node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Function to push element to stack
void push(int vertex) {
    stack[++top] = vertex;
}

// Function to pop element from stack
int pop() {
    return stack[top--];
}

// Iterative DFS function using a stack
void dfsIterative(int start) {
    push(start);
    visited[start] = true;

    while (top != -1) {
        int vertex = pop();
        printf("%d ", vertex);

        // Visit all adjacent vertices
        Node* temp = adjList[vertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                push(adjVertex);
                visited[adjVertex] = true;
            }
            temp = temp->next;
        }
    }
}

// Driver code
int main() {
    // Initialize adjacency list
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjList[i] = NULL;
        visited[i] = false;
    }

    // Create a sample graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);

    printf("DFS Traversal (Iterative):\n");
    dfsIterative(0);  // Start DFS traversal from vertex 0
    printf("\n");

    return 0;
}