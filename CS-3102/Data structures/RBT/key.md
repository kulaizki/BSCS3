## Insertion
- **Properties**: Red-Black trees are binary search trees (BST) with an additional color property for each node (either red or black). They enforce these rules:
  - The root is always black.
  - Red nodes cannot have red children (no two red nodes can be adjacent).
  - Every path from a node to its descendant NULL nodes must have the same number of black nodes.

- **Insertion Steps**:
  1. Insert the new node following BST rules (place it in the correct position based on its value).
  2. Initially color the new node red.
  3. Fix any violations of the Red-Black Tree properties using rotations and recoloring:
     - **Case 1**: Uncle node is red → Recolor the parent and uncle to black, recolor the grandparent to red, and move `z` up.
     - **Case 2**: Node `z` is the right child → Perform a left rotation and adjust the tree.
     - **Case 3**: Rebalance with rotations if necessary (left or right rotation) and adjust colors.
  
- **Rotation**:
  - **Left Rotate**: Used when a right child needs to be moved up to balance the tree.
  - **Right Rotate**: Used when a left child needs to be moved up to balance the tree.

- **Time Complexity**: O(log n) due to the properties of the tree maintaining a balanced structure.

## Deletion
- **Deletion Steps**:
  1. **Find the node** to be deleted. If the node has two children, find the in-order successor (leftmost node in the right subtree) and replace the node.
  2. If the node has one child, replace the node with its child.
  3. **Fix the tree** to maintain Red-Black Tree properties:
     - **Case 1**: Sibling is red → Rotate and recolor to move the red sibling up and restore balance.
     - **Case 2**: Sibling and its children are black → Recolor the sibling to red and move up.
     - **Case 3**: Perform rotations if necessary to restore tree balance after deletion.

- **Fixing Deletion**:
  - After a deletion, the tree may become unbalanced (e.g., may create two consecutive black nodes on the path). The `fixDelete` function restores the balance using rotations and recoloring to maintain the Red-Black properties.

- **Time Complexity**: O(log n) because the tree remains balanced, and operations are limited to a logarithmic number of levels in the worst case.

## Key Differences from Other Trees
- **Balance**: Red-Black Trees are self-balancing BSTs where balancing is achieved through color flips and rotations. 
- **Insertion and Deletion**: Both operations require adjustments to the tree using rotations and color changes to ensure the tree remains balanced and adheres to Red-Black properties.
- **Performance**: The operations are guaranteed to take O(log n) time, which is better than unbalanced BSTs, where the time complexity could degrade to O(n) in the worst case.
- **Unique Property**: Unlike AVL Trees, which strictly balance height, Red-Black Trees allow for a less strict balance, resulting in simpler insertion and deletion logic but still maintaining logarithmic time complexity for operations.