## Problem Statement

You are given an **N-ary tree** in the **Left Child - Right Sibling (LCRS)** representation. Each node is defined by the following structure:

```c
typedef struct TreeNode {
    int val;
    struct TreeNode* parent;
    struct TreeNode* left_child;
    struct TreeNode* right_sibling;
} TreeNode;
```

You must implement the following three functions (their signatures must not be changed):

1. **`int height(TreeNode *node)`**  
   - Returns the height of the tree rooted at `node`.  
   - In this problem, a **leaf node** has height 0.

2. **`int maxChildren(TreeNode *node)`**  
   - Returns the maximum number of children (direct descendants) that any single node in the subtree rooted at `node` has.  
   - If a node has multiple children, you can access them by following its `left_child` and each child’s `right_sibling` pointer.

3. **`void bfs(TreeNode *node)`**  
   - Performs a breadth-first traversal starting from `node` and prints the `val` of each visited node in order (level by level).

### Example Tree

Consider the following tree structure (in LCRS form):

```
               (A)
             /   |   \
           (B)  (C)  (D)
           / \        \
         (E) (F)       (G)
                      /  |  \
                    (H) (I) (J)
```

- `A` has three children: `B`, `C`, and `D`.  
  - `A->left_child = B; B->right_sibling = C; C->right_sibling = D;`
- `B` has two children: `E` and `F`.  
  - `B->left_child = E; E->right_sibling = F;`
- `C` has no children (`C->left_child = NULL`).
- `D` has one child: `G` (`D->left_child = G`).
- `G` has three children: `H`, `I`, `J`.  
  - `G->left_child = H; H->right_sibling = I; I->right_sibling = J;`
- `E`, `F`, `H`, `I`, and `J` are leaves (no children).

1. **Height**: Calling `height(A)` on the root should return the overall height of this tree.  
2. **Max Children**: Calling `maxChildren(A)` should return the largest number of direct children of any node in the subtree rooted at `A`.  
3. **BFS**: Calling `bfs(A)` should print out the node values in level-order, starting with `A`.
