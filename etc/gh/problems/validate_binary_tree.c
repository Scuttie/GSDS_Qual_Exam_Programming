#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

bool helper(TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;
    
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }
    
    return helper(root->left, minVal, root->data) && helper(root->right, root->data, maxVal);
}

bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // 이진 트리 구성 (유효한 BST)
    TreeNode* root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);
    
    // BST 유효성 검사 및 출력
    bool result = isValidBST(root);
    printf("Is Valid BST: %s\n", result ? "true" : "false");
    
    // 동적 메모리 해제
    free(root->left);
    free(root->right);
    free(root);
    
    return 0;
}
