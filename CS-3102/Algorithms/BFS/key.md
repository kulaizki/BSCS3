- **Purpose**: Traverses or searches a graph by exploring all neighbors at the present depth level before moving on to nodes at the next level.

- **Approaches**:
  1. **Queue-based BFS**: Uses a queue to explore nodes level by level, ensuring that all nodes at a certain distance are processed before those at a greater distance.

- **Graph Representation**: Typically uses an **adjacency list** where each node points to its neighbors.

- **Time Complexity**: **O(V + E)**, where **V** is vertices and **E** is edges.

- **Space Complexity**: **O(V)**, for visited array and queue.

- **Visited Array**: Keeps track of visited nodes to prevent revisiting and avoid infinite loops.

- **Process**:
  1. Start from the source node, mark it as visited, and enqueue it.
  2. Dequeue a node, process it, and enqueue all unvisited neighbors.
  3. Repeat until the queue is empty.

- **Key Concepts**:
  - **Level-order traversal**: BFS explores nodes level by level, ensuring that the nodes closest to the source are processed first.
  - **Queue**: A queue is used to hold nodes during exploration in FIFO (First In, First Out) order.
  - **Shortest path**: BFS guarantees the shortest path in an unweighted graph, since it explores all nodes at a particular level before moving deeper.
  - **Breadth-first exploration**: BFS explores all possible paths in the graph from the starting point before moving to the next level.