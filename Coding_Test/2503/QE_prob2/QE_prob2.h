#ifndef QE_PROB2_H
#define QE_PROB2_H

typedef struct TreeNode {
    struct TreeNode *left_child;
    struct TreeNode *right_sibling;
    struct TreeNode *parent;
    int val;
} TreeNode; 

TreeNode *create_node(int val);
int height(TreeNode *node);
int n_ary(TreeNode *node);
void bfs(TreeNode *node);

#endif
