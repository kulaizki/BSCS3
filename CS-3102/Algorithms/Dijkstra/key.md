- **Purpose**: Finds the shortest path from a source vertex to all other vertices in a weighted graph.

- **Approaches**:
  1. **Greedy Approach**: Select the vertex with the smallest tentative distance and explore its neighbors, updating their distances.
  2. **Priority Queue**: A min-heap or priority queue is often used to efficiently select the vertex with the smallest tentative distance.

- **Graph Representation**: Uses **adjacency matrix** or **adjacency list** where each vertex points to its neighbors and associated edge weights.

- **Time Complexity**: 
  - **O(V^2)** using simple array-based implementation.
  - **O(E + V log V)** when using a priority queue with a binary heap.

- **Space Complexity**: **O(V)**, for storing distances, visited status, and parent pointers.

- **Visited Array**: Tracks visited nodes to avoid processing the same node more than once.

- **Process**:
  1. Start from the source vertex, initialize its distance to 0 and others to infinity.
  2. Select the unvisited vertex with the smallest tentative distance.
  3. Update the tentative distances of its neighbors.
  4. Mark the selected vertex as visited.
  5. Repeat until all vertices are visited or the shortest path to all vertices is found.

- **Key Concepts**:
  - **Greedy Choice**: At each step, Dijkstra's algorithm picks the vertex with the smallest tentative distance, ensuring that the path is progressively optimized.
  - **Priority Queue**: A min-heap structure is often used to efficiently fetch the vertex with the smallest tentative distance.
  - **Relaxation**: The process of updating the shortest known distance to a vertex.
  - **Optimal Substructure**: The shortest path from the source to any vertex can be built from the shortest paths to its predecessors.