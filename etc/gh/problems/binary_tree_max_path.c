#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int max(int a, int b) {
    return a > b ? a : b;
}

int helper(TreeNode* root, int* maxSum) {
    if (!root) return 0;
    
    int left = max(0, helper(root->left, maxSum));
    int right = max(0, helper(root->right, maxSum));
    
    *maxSum = max(*maxSum, left + right + root->data);
    
    return max(left, right) + root->data;
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    helper(root, &maxSum);
    return maxSum;
}

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // 이진 트리 구성
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    
    // 최대 경로 합 계산 및 출력
    int result = maxPathSum(root);
    printf("Maximum Path Sum: %d\n", result);
    
    // 동적 메모리 해제
    free(root->left);
    free(root->right);
    free(root);
    
    return 0;
}
