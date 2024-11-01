/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;      // 방문한 노드 수
        int result = -1;    // 결과를 저장할 변수
        inorder(root, k, count, result);
        return result;
    }
    
private:
    void inorder(TreeNode* node, int k, int &count, int &result) {
        if (!node || count >= k) return;

        // 왼쪽 서브트리 순회
        inorder(node->left, k, count, result);
        
        // 현재 노드 방문
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        
        // 오른쪽 서브트리 순회
        inorder(node->right, k, count, result);
    }
};
