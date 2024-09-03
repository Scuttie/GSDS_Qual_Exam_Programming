#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_node(int data) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_left(TreeNode* current_node, int data) {
    if (current_node->left == NULL) {
        current_node->left = create_node(data);
    } else {
        TreeNode* new_node = create_node(data);
        new_node->left = current_node->left;
        current_node->left = new_node;
    }
}

void insert_right(TreeNode* current_node, int data) {
    if (current_node->right == NULL) {
        current_node->right = create_node(data);
    } else {
        TreeNode* new_node = create_node(data);
        new_node->right = current_node->right;
        current_node->right = new_node;
    }
}

void inorder_traversal(TreeNode* node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

void preorder_traversal(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}

void postorder_traversal(TreeNode* node) {
    if (node != NULL) {
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    TreeNode* root = create_node(1);
    insert_left(root, 2);
    insert_right(root, 3);
    insert_left(root->left, 4);
    insert_right(root->left, 5);

    printf("Inorder traversal:\n");
    inorder_traversal(root);  // 출력: 4 2 5 1 3
    printf("\n");

    printf("Preorder traversal:\n");
    preorder_traversal(root);  // 출력: 1 2 4 5 3
    printf("\n");

    printf("Postorder traversal:\n");
    postorder_traversal(root);  // 출력: 4 5 2 3 1
    printf("\n");

    return 0;
}
