#include <iostream>

// 이진 트리의 노드 정의
struct TreeNode {
    int val;            // 노드의 값
    TreeNode *left;     // 왼쪽 자식 노드
    TreeNode *right;    // 오른쪽 자식 노드
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * 이 함수는 주어진 이진 트리의 최대 깊이를 반환합니다.
     * 최대 깊이는 루트 노드에서 가장 먼 리프 노드까지의 노드 수를 의미합니다.
     * 
     * @param root 이진 트리의 루트 노드
     * @return 이진 트리의 최대 깊이
     */
    int maxDepth(TreeNode* root) {
        // 기본 사례: 노드가 없으면 깊이는 0
        if (root == nullptr) {
            return 0;
        }
        
        // 재귀 호출을 통해 왼쪽과 오른쪽 서브트리의 깊이를 계산
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // 왼쪽과 오른쪽 깊이 중 더 큰 값을 선택하고, 현재 노드를 포함하여 깊이를 1 증가시킴
        return std::max(leftDepth, rightDepth) + 1;
    }
};

// 테스트를 위한 메인 함수 (선택 사항)
int main() {
    Solution solution;
    
    // 예제 1:
    // 트리 구조:
    //      3
    //     / \
    //    9  20
    //       / \
    //      15  7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    std::cout << "예제 1 출력: " << solution.maxDepth(root1) << std::endl; // 출력: 3
    
    // 메모리 해제
    delete root1->right->right;
    delete root1->right->left;
    delete root1->right;
    delete root1->left;
    delete root1;
    
    // 예제 2:
    // 트리 구조:
    //      1
    //       \
    //        2
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    
    std::cout << "예제 2 출력: " << solution.maxDepth(root2) << std::endl; // 출력: 2
    
    // 메모리 해제
    delete root2->right;
    delete root2;
    
    return 0;
}
