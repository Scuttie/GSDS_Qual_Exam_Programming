#include <iostream>
#include <algorithm>
#include <climits>

// 이진 트리의 노드 구조체 정의
struct TreeNode {
    int val;            // 노드의 값
    TreeNode *left;     // 왼쪽 자식 노드
    TreeNode *right;    // 오른쪽 자식 노드
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // 기본 생성자
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 값이 있는 생성자
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // 값과 자식 노드가 있는 생성자
};

class Solution {
public:
    /**
     * 이 함수는 주어진 이진 트리에서 조상과 자손 노드 간의 값 차이의 최댓값을 찾습니다.
     * 조상과 자손 노드 간의 차이는 |a.val - b.val|으로 정의되며, a는 b의 조상입니다.
     * 
     * @param root 이진 트리의 루트 노드
     * @return 조상과 자손 노드 간의 값 차이의 최댓값
     */
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0; // 트리가 비어있으면 차이는 0

        int max_diff = 0; // 최대 차이를 저장할 변수 초기화

        // 재귀적으로 트리를 순회하며 최대 차이를 계산하는 헬퍼 함수 호출
        dfs(root, root->val, root->val, max_diff);

        return max_diff; // 최종적으로 계산된 최대 차이 반환
    }

private:
    /**
     * 이 함수는 현재 노드와 그 조상 노드들 사이의 값 차이를 계산하여 최대 차이를 업데이트합니다.
     * 
     * @param node 현재 탐색 중인 노드
     * @param current_min 현재 경로에서의 최소 값
     * @param current_max 현재 경로에서의 최대 값
     * @param max_diff 현재까지 발견된 최대 차이를 저장하는 참조 변수
     */
    void dfs(TreeNode* node, int current_min, int current_max, int &max_diff) {
        if (node == nullptr) return; // 노드가 없으면 반환

        // 현재 노드의 값과 경로의 최소/최대 값을 비교하여 업데이트
        current_min = std::min(current_min, node->val);
        current_max = std::max(current_max, node->val);

        // 현재 노드와 경로의 최소/최대 값 사이의 차이를 계산하여 최대 차이 업데이트
        max_diff = std::max(max_diff, current_max - current_min);

        // 왼쪽 자식 노드로 재귀 호출
        dfs(node->left, current_min, current_max, max_diff);
        // 오른쪽 자식 노드로 재귀 호출
        dfs(node->right, current_min, current_max, max_diff);
    }
};

// 테스트를 위한 메인 함수 (선택 사항)
int main() {
    Solution solution;

    // 예제 1:
    // 트리 구조:
    //       8
    //      / \
    //     3   10
    //    / \    \
    //   1   6    14
    //      / \   /
    //     4   7 13
    TreeNode* root1 = new TreeNode(8);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(10);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(6);
    root1->left->right->left = new TreeNode(4);
    root1->left->right->right = new TreeNode(7);
    root1->right->right = new TreeNode(14);
    root1->right->right->left = new TreeNode(13);

    int result1 = solution.maxAncestorDiff(root1);
    std::cout << "예제 1 출력: " << result1 << std::endl; // 예상 출력: 7

    // 메모리 해제
    delete root1->right->right->left;
    delete root1->right->right;
    delete root1->left->right->right;
    delete root1->left->right->left;
    delete root1->left->right;
    delete root1->left->left;
    delete root1->left;
    delete root1->right;
    delete root1;

    // 예제 2:
    // 트리 구조:
    //       1
    //        \
    //         2
    //          \
    //           0
    //          /
    //         3
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(0);
    root2->right->right->left = new TreeNode(3);

    int result2 = solution.maxAncestorDiff(root2);
    std::cout << "예제 2 출력: " << result2 << std::endl; // 예상 출력: 3

    // 메모리 해제
    delete root2->right->right->left;
    delete root2->right->right;
    delete root2->right;
    delete root2;

    return 0;
}
