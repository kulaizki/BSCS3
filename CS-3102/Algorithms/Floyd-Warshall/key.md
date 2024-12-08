- **Purpose**: Computes the shortest paths between all pairs of vertices in a weighted graph, including negative weights (but no negative weight cycles).

- **Approach**:
  - The algorithm uses dynamic programming to progressively improve estimates of the shortest paths.
  - Iterates over all vertices as intermediate nodes to check if a shorter path exists through them.

- **Graph Representation**: The graph is represented as an **adjacency matrix** where `graph[i][j]` is the edge weight from vertex `i` to vertex `j`. A value of `INF` represents no direct path.

- **Time Complexity**: **O(V³)**, where **V** is the number of vertices, as there are three nested loops iterating over the vertices.

- **Space Complexity**: **O(V²)**, for the distance matrix that stores the shortest distances between each pair of vertices.

- **Process**:
  1. Initialize the distance matrix with graph's direct distances.
  2. For each possible intermediate vertex `k`, update the distance between every pair of vertices `(i, j)` by checking if the path `i -> k -> j` is shorter than the direct path `i -> j`.
  3. Repeat until no shorter paths are found (when all vertices have been considered as intermediate vertices).

- **Key Concepts**:
  - **Distance Matrix**: A matrix `dist[i][j]` representing the shortest path distance from vertex `i` to vertex `j`.
  - **Intermediate Vertices**: Vertices that are considered as potential intermediate steps to improve the path from `i` to `j`.
  - **Dynamic Programming**: Updates the shortest paths progressively by considering paths through intermediate vertices.
  - **No Negative Weight Cycles**: The algorithm works only if there are no negative weight cycles in the graph, as they would cause the shortest path to be undefined.