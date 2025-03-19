#include "stdio.h"
#include "stdlib.h"
#include "QE_prob2.h"

#define MAX 1000

TreeNode *create_node(int val){
    TreeNode *newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
    newTreeNode->left_child = NULL;
    newTreeNode->parent = NULL;
    newTreeNode->right_sibling = NULL;
    newTreeNode->val = val;

    return newTreeNode;
}

// 새 노드 생성
TreeNode* create_node(int val) {
    TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
    newTreeNode->val = val;
    newTreeNode->parent = NULL;
    newTreeNode->left_child = NULL;
    newTreeNode->right_sibling = NULL;
    return newTreeNode;
}

/**
 * 트리 높이 구하기(leaf = 0)
 * LCRS에서의 재귀 정의:
 * - node == NULL -> return 0
 * - 있으면 1 + (left_child의 높이 중 최댓값)
 *   형제는 "같은 레벨"이므로, 현재 노드의 높이를 따질 때
 *   right_sibling의 높이도 비교해야 함
 */
int height(TreeNode* node) {
    if (node == NULL) return 0;

    int child_height = 0;
    if (node->left_child != NULL) {
        // 왼쪽 자식 방향 높이는 1 + 그 자식의 높이
        child_height = 1 + height(node->left_child);
    }

    // 형제 노드의 높이도 구해서 더 큰 값 반환
    // (형제 쪽이 더 높을 수는 없지만, "전체"를 본다면 형제 트리가 더 클 수도 있으니 비교)
    int sibling_height = height(node->right_sibling);

    return (child_height > sibling_height) ? child_height : sibling_height;
}

/**
 * 트리에서 "최대 자식 수"를 구함
 * - 각 노드마다, 그 노드의 left_child 부터 right_sibling 체인으로 이어지는
 *   "자식"의 수를 세고, 그 중 최댓값을 찾는다.
 * - BFS로 모든 노드를 한 번씩 방문하면서 검사하면 간단
 */
int n_ary(TreeNode* root) {
    if (root == NULL) return 0;

    TreeNode* queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int max_children = 0;

    while (front < rear) {
        TreeNode* curr = queue[front++];
        // curr의 자식(왼쪽 자식 + 그 형제들)의 수 세기
        int count = 0;
        TreeNode* child = curr->left_child;
        while (child != NULL) {
            count++;
            // 그 child도 큐에 넣는다(다음 레벨 방문)
            if (rear < MAX) { // 오버플로 체크
                queue[rear++] = child;
            }
            child = child->right_sibling;
        }
        if (count > max_children) {
            max_children = count;
        }
    }

    return max_children;
}

/**
 * 표준 BFS 순회: root부터 레벨 순서대로 curr->val을 출력
 * - LCRS 트리에서도, "현재 노드의 자식들"을 큐에 넣는 식으로 처리
 * - 형제 노드는 "부모"가 큐에서 빠질 때 자식들로 한꺼번에 삽입
 */
void bfs(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* curr = queue[front++];
        // 방문
        printf("%d ", curr->val);

        // curr의 자식들(왼쪽 자식 ~ 형제들)을 큐에 삽입
        TreeNode* child = curr->left_child;
        while (child != NULL) {
            if (rear < MAX) {
                queue[rear++] = child;
            }
            child = child->right_sibling;
        }
    }
    printf("\n");
}


// REMOVE this main function for submission
int main() { 
    TreeNode *ANode = create_node(1);
    TreeNode *BNode = create_node(2);
    TreeNode *CNode = create_node(3);
    TreeNode *DNode = create_node(4);
    TreeNode *ENode = create_node(5);
    TreeNode *FNode = create_node(6);
    TreeNode *GNode = create_node(7);
    TreeNode *HNode = create_node(8);
    TreeNode *INode = create_node(9);
    TreeNode *JNode = create_node(10);
    TreeNode *KNode = create_node(11);
    TreeNode *LNode = create_node(12);

    ANode->parent = NULL;
    ANode->right_sibling = NULL;
    ANode->left_child = BNode;

    printf("%d\n", height(ANode));

    BNode->parent = ANode;
    BNode->right_sibling = CNode;
    BNode->left_child = DNode;

    printf("%d\n", height(ANode));

    CNode->parent = ANode;
    CNode->right_sibling = NULL;
    CNode->left_child = FNode;

    printf("%d\n", height(ANode));

    DNode->parent = BNode;
    DNode->right_sibling = ENode;
    DNode->left_child = NULL;

    printf("%d\n", height(ANode));

    ENode->parent = BNode;
    ENode->right_sibling = NULL;
    ENode->left_child = JNode;

    printf("%d\n", height(ANode));

    FNode->parent = CNode;
    FNode->right_sibling = GNode;
    FNode->left_child = NULL;

    GNode->parent = CNode;
    GNode->right_sibling = HNode;
    GNode->left_child = KNode;

    HNode->parent = CNode;
    HNode->right_sibling = INode;
    HNode->left_child = NULL;

    INode->parent = CNode;
    INode->right_sibling = NULL;
    INode->left_child = NULL;

    JNode->parent = ENode;
    JNode->right_sibling = NULL;
    JNode->left_child = NULL;
    
    KNode->parent = GNode;
    KNode->right_sibling = LNode;
    KNode->left_child = NULL;

    LNode->parent = GNode;
    LNode->right_sibling = NULL;
    LNode->left_child = NULL;

    printf("%d\n", height(ANode));

    printf("%d\n", n_ary(ANode));

    bfs(ANode);
    
    return 0;
}

