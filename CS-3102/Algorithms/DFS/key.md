- **Purpose**: Traverses or searches tree/graph by exploring as far as possible along each branch before backtracking.

- **Approaches**:
  1. **Recursive DFS**: Simple, uses the call stack implicitly, but can cause stack overflow for large graphs.
  2. **Iterative DFS**: Uses an explicit stack to avoid stack overflow and simulate recursion.

- **Graph Representation**: Uses **adjacency list** where each vertex points to its neighbors.

- **Time Complexity**: **O(V + E)**, where **V** is vertices and **E** is edges.

- **Space Complexity**: **O(V)**, for visited array and stack.

- **Visited Array**: Tracks visited nodes to prevent revisiting.

- **Process**:
  1. Start from a node, mark it as visited.
  2. Recursively (or iteratively) visit all unvisited neighbors of the current node.
  3. Backtrack when no unvisited neighbors remain.
  4. Repeat until all nodes in the component are visited.

- **Key Concepts**:
  - **Backtracking**: DFS explores a path as far as possible, and when it hits a dead end, it backtracks to explore other paths.
  - **Depth**: DFS explores deeper into the graph before considering other nodes.
  - **Stack**: A stack (explicit or via recursion) is used to remember the path being explored.
  - **Tree Traversal**: DFS can be used for pre-order, in-order, and post-order tree traversal.





