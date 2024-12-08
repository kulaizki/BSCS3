### 2-3 Tree Notes

- **Self-balancing search tree**: All leaf nodes are at the same level, ensuring balanced search times.
- **Node Structure**:
  - Each node can store **1 or 2 keys**.
  - A node can have **2 or 3 children**.
  - **Leaf nodes** store only keys, while **internal nodes** store keys and child pointers.
  
- **Key Operations**:
  - **Insertion**:
    - When inserting a key into a non-full node, the key is placed in the correct position among the existing keys.
    - If the node is full (2 keys), it splits into two nodes:
      - The middle key is promoted to the parent node.
      - If the parent is full, it also splits recursively.
  - **Splitting**:
    - When a child node is full (contains 2 keys), it splits:
      - The middle key of the child is promoted to the parent.
      - The child’s keys are redistributed between the two new child nodes.
      - The parent may need to split if it becomes full.
  - **Search**:
    - The search operation is similar to binary search in each node, checking each key and following the correct child pointer.

- **Time Complexity**:
  - **Insertion and Search**: O(log n), where `n` is the number of keys in the tree.
  - The tree remains balanced, ensuring logarithmic time for operations.

- **Space Complexity**: O(n), where `n` is the number of keys in the tree.

- **Differences from Other Trees**:
  - Unlike a **binary search tree (BST)**, which has at most 2 children per node, a **2-3 tree** has nodes that can have either 2 or 3 children.
  - The **B-tree** allows multiple keys in a node, but a **2-3 tree** is a simpler variant of the B-tree with a specific restriction (2 or 3 children and 1 or 2 keys).
  - **Self-balancing**: 2-3 trees are always balanced, while other trees like **AVL trees** or **red-black trees** may require rotations to maintain balance during insertions and deletions.
  - **Splitting logic**: In a 2-3 tree, internal nodes may split when full, and the middle key is promoted. This is different from other trees like **B-trees**, where splitting might involve more complex restructuring.
