- **Purpose**: Finds the shortest paths from a source vertex to all other vertices in a graph, even with negative edge weights.

- **Approaches**:
  1. **Relaxation**: Repeatedly updates the shortest path estimates for all edges.
  2. **Negative Weight Cycle Detection**: Checks for negative weight cycles after V-1 relaxations.

- **Graph Representation**: 
  - Uses **edge list** to represent the graph, where each edge has a source, destination, and weight.

- **Time Complexity**: **O(V * E)**, where **V** is the number of vertices and **E** is the number of edges.

- **Space Complexity**: **O(V + E)**, for storing the graph and distance array.

- **Process**:
  1. Initialize distances to infinity for all vertices except the source, which is set to 0.
  2. For **V-1** iterations, relax each edge (update distances if a shorter path is found).
  3. After V-1 relaxations, check for negative-weight cycles by relaxing the edges one more time.
  4. If any edge can still be relaxed, a negative-weight cycle exists.

- **Key Concepts**:
  - **Relaxation**: Updating the shortest distance to a vertex by considering an edge and its weight.
  - **Negative-Weight Cycles**: A cycle in which the sum of the edge weights is negative, which can cause incorrect results.
  - **Edge List**: A simple way to store the graph, used in Bellman-Ford for efficiency.
  - **Distance Array**: Tracks the shortest distance from the source to each vertex.