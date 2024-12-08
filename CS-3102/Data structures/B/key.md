- **definition**: self-balancing search tree maintaining sorted data with efficient insertion, deletion, and search.
- **key property**: each node has at most `2t - 1` keys and at least `t - 1` keys (except the root).

- **node structure**:
  - contains `n` keys (`n <= 2t - 1`).
  - has `n + 1` child pointers if not a leaf.
  - all leaves are at the same depth.

- **time complexity**:
  - search: `o(log n)`.
  - insertion: `o(log n)`.
  - deletion: `o(log n)`.

- **search**:
  - uses binary search within nodes.
  - recurs into appropriate child if not found.

- **insertion**:
  - starts at the root, inserts into a leaf if possible.
  - splits full nodes while traversing down.
  - may increase height if the root splits.

- **deletion**:
  - handles three cases:
    1. **key in a leaf node**: remove the key.
    2. **key in an internal node**: replace with predecessor/successor and recursively delete.
    3. **key not in node**: ensure child has at least `t` keys (merge or borrow if needed).

- **node splitting**:
  - occurs when a node reaches `2t - 1` keys during insertion.
  - middle key promoted to parent.
  - splits into two nodes, each with `t - 1` keys.

- **balance**:
  - always balanced due to splitting and merging.
  - height is logarithmic in the number of keys.