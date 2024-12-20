- A self-balancing search tree similar to a B-tree but with a more restrictive node splitting process.
- Each node stores a list of keys and pointers to child nodes.

- **Minimum degree (t)** determines the maximum number of children for each node.

- **Key properties**:
  - Nodes can have between `t-1` and `2t-1` keys.
  - Internal nodes have at least `t` children.
  - Leaves have between `t-1` and `2t-1` keys.

- **Insert operation**:
  - If a node is full, it splits into three parts, redistributing keys between the node and its sibling.
  - The splitting process ensures better space utilization.

- **Split process**:
  - When a child node is full, it is split into two nodes, and a key is promoted to the parent node.
  - If the parent node is also full, it too is split.

- **Inorder traversal** prints keys in ascending order.

- **Time complexity**:
  - Search, insertion, and deletion: O(log n), where `n` is the number of keys in the tree.
  - Due to its balanced nature, all operations have logarithmic complexity.

- **Space complexity**: O(n) for storing the keys and children pointers.

- **Use cases**:
  - Effective for databases, file systems, and large-scale data storage systems that require efficient insertion, deletion, and search operations.