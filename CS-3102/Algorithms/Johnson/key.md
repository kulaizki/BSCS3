- **Purpose**: Solves the all-pairs shortest path problem efficiently, even for graphs with negative edge weights (but no negative weight cycles).

- **Approaches**:
  1. **Reweighting**: Adds a new vertex and reweights the edges using Bellman-Ford to eliminate negative weights.
  2. **Dijkstra's Algorithm**: After reweighting, Dijkstra's algorithm is run for each vertex to find the shortest paths.

- **Graph Representation**: 
  - Uses **adjacency matrix** or **adjacency list** for efficient edge lookup.

- **Time Complexity**: **O(V^2 log V + VE)**, where **V** is the number of vertices and **E** is the number of edges.

- **Space Complexity**: **O(V^2)** for storing the reweighted graph.

- **Process**:
  1. Add a new vertex **s** connected to all other vertices with edges of weight 0.
  2. Use **Bellman-Ford** from vertex **s** to find shortest paths from **s** to all other vertices.
  3. Reweight all edges based on the results of Bellman-Ford.
  4. Remove the added vertex **s** and apply **Dijkstra’s algorithm** from each vertex to compute all pairs shortest paths.

- **Key Concepts**:
  - **Reweighting**: Adjusts the edge weights to ensure all edge weights are non-negative, allowing Dijkstra's algorithm to work.
  - **Bellman-Ford**: Used initially to handle negative weights and to provide the reweighting function.
  - **Dijkstra's Algorithm**: After reweighting, Dijkstra's is used to efficiently compute the shortest paths from each vertex.
  - **All-Pairs Shortest Path**: Computes the shortest paths between all pairs of vertices, which can be used in various network flow problems and route optimization.