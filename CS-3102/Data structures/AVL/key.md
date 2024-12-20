- **definition**: self-balancing binary search tree where the difference in heights between left and right subtrees is at most 1 for every node.
- **height**: each node stores a height value used to calculate balance factors.
- **balance factor**: `balanceFactor = height(left subtree) - height(right subtree)`; valid range: `-1, 0, 1`.

- **rotations**:
  - **right rotation**: performed when left subtree is too heavy.
  - **left rotation**: performed when right subtree is too heavy.
  - **left-right rotation**: a combination of left then right rotations.
  - **right-left rotation**: a combination of right then left rotations.

- **insertion**:
  - follows standard BST insertion.
  - after insertion, height is updated, and the tree is balanced using rotations if necessary.

- **deletion**: follows BST deletion rules, ensuring balance is maintained after removal.

- **time complexity**:
  - search, insertion, and deletion: `O(log n)` due to balanced tree structure.
- **space complexity**: `O(n)` for storing nodes.

- **use cases**: useful when frequent insertions and deletions are needed with balanced search times (e.g., database indexing).