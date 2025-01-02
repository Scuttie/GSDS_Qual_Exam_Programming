#include <stdio.h>
#include <stdlib.h>

/*
문제 설명:

n-ary 트리가 주어졌을 때, 그 트리의 최대 깊이를 찾는 문제입니다.
최대 깊이는 루트 노드에서 가장 먼 리프 노드까지의 경로에 있는 노드의 수를 의미합니다.

n-ary 트리의 입력은 레벨 순서(level order) 순회로 표현되며, 각 자식 그룹은 null 값으로 구분됩니다.

예를 들어:
- 예제 1:
    입력: root = [1,null,3,2,4,null,5,6]
    출력: 3
    설명: 트리의 최대 깊이는 3입니다.
- 예제 2:
    입력: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    출력: 5
    설명: 트리의 최대 깊이는 5입니다.

제약 조건:
- 노드의 총 개수는 [0, 10^4] 범위에 있습니다.
- n-ary 트리의 깊이는 1000을 넘지 않습니다.
*/

typedef struct Node {
    int val;                // 노드의 값
    struct Node** children; // 자식 노드들을 가리키는 포인터 배열
    int numChildren;        // 자식 노드의 개수
} Node;

// 노드를 생성하는 함수
Node* createNode(int val, int numChildren) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->numChildren = numChildren;
    if (numChildren > 0) {
        newNode->children = (Node**)malloc(sizeof(Node*) * numChildren);
        if (!newNode->children) {
            fprintf(stderr, "메모리 할당 실패\n");
            free(newNode);
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < numChildren; i++) {
            newNode->children[i] = NULL;
        }
    }
    else {
        newNode->children = NULL;
    }
    return newNode;
}

// 노드를 해제하는 함수
void freeNode(Node* root) {
    if (!root) return;
    for(int i = 0; i < root->numChildren; i++) {
        if (root->children[i]) {
            freeNode(root->children[i]);
        }
    }
    free(root->children);
    free(root);
}

// 최대 깊이를 계산하는 함수 (재귀적 DFS 방식)
int maxDepth(Node* root) {
    if (!root) {
        return 0; // 트리가 비어있으면 깊이는 0
    }
    if (root->numChildren == 0) {
        return 1; // 리프 노드면 깊이는 1
    }
    int max_depth = 0;
    for(int i = 0; i < root->numChildren; i++) {
        int current_depth = maxDepth(root->children[i]);
        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
    }
    return max_depth + 1; // 현재 노드를 포함하여 깊이 증가
}

// 테스트 케이스 1:
// Input: [1,null,3,2,4,null,5,6]
// Expected Output: 3
Node* buildTestCase1() {
    // 노드 생성
    Node* root = createNode(1, 3); // 루트 노드 1, 자식 3개
    root->children[0] = createNode(3, 2); // 자식 3, 자식 2개
    root->children[1] = createNode(2, 0); // 자식 2, 자식 없음
    root->children[2] = createNode(4, 0); // 자식 4, 자식 없음
    root->children[0]->children[0] = createNode(5, 0); // 자식 5, 자식 없음
    root->children[0]->children[1] = createNode(6, 0); // 자식 6, 자식 없음
    return root;
}

// 테스트 케이스 2:
// Input: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Expected Output: 5
Node* buildTestCase2() {
    // 노드 생성
    Node* root = createNode(1, 4); // 루트 노드 1, 자식 4개
    root->children[0] = createNode(2, 1); // 자식 2, 자식 1개
    root->children[1] = createNode(3, 1); // 자식 3, 자식 1개
    root->children[2] = createNode(4, 1); // 자식 4, 자식 1개
    root->children[3] = createNode(5, 1); // 자식 5, 자식 1개
    
    root->children[0]->children[0] = createNode(6, 2); // 자식 6, 자식 2개
    root->children[0]->children[0]->children[0] = createNode(11, 0); // 자식 11, 자식 없음
    root->children[0]->children[0]->children[1] = createNode(12, 0); // 자식 12, 자식 없음
    
    root->children[1]->children[0] = createNode(7, 1); // 자식 7, 자식 1개
    root->children[1]->children[0]->children[0] = createNode(13, 0); // 자식 13, 자식 없음
    
    root->children[2]->children[0] = createNode(8, 1); // 자식 8, 자식 1개
    root->children[2]->children[0]->children[0] = createNode(14, 0); // 자식 14, 자식 없음
    
    root->children[3]->children[0] = createNode(9, 1); // 자식 9, 자식 1개
    root->children[3]->children[0]->children[0] = createNode(10, 0); // 자식 10, 자식 없음
    
    return root;
}

// 테스트 케이스 3: 단일 노드
// Input: [1]
// Expected Output: 1
Node* buildTestCase3() {
    Node* root = createNode(1, 0); // 루트 노드 1, 자식 없음
    return root;
}

// 테스트 케이스 4: 빈 트리
// Input: []
// Expected Output: 0
Node* buildTestCase4() {
    return NULL;
}

// 테스트 케이스 5: 두 레벨
// Input: [1,null,2,3,4,5]
// Expected Output: 2
Node* buildTestCase5() {
    Node* root = createNode(1, 4); // 루트 노드 1, 자식 4개
    root->children[0] = createNode(2, 0); // 자식 2, 자식 없음
    root->children[1] = createNode(3, 0); // 자식 3, 자식 없음
    root->children[2] = createNode(4, 0); // 자식 4, 자식 없음
    root->children[3] = createNode(5, 0); // 자식 5, 자식 없음
    return root;
}

// 테스트 케이스 6: 깊은 트리
// Input: [1,null,2,null,3,null,4,null,5]
// Expected Output: 5
Node* buildTestCase6() {
    Node* root = createNode(1, 1); // 루트 노드 1, 자식 1개
    root->children[0] = createNode(2, 1); // 자식 2, 자식 1개
    root->children[0]->children[0] = createNode(3, 1); // 자식 3, 자식 1개
    root->children[0]->children[0]->children[0] = createNode(4, 1); // 자식 4, 자식 1개
    root->children[0]->children[0]->children[0]->children[0] = createNode(5, 0); // 자식 5, 자식 없음
    return root;
}

// 테스트 케이스 7: 여러 브랜치
// Input: [1,null,2,3,4,5,null,6,7,null,8,9]
// Expected Output: 4
Node* buildTestCase7() {
    Node* root = createNode(1, 4); // 루트 노드 1, 자식 4개
    root->children[0] = createNode(2, 1); // 자식 2, 자식 1개
    root->children[0]->children[0] = createNode(6, 0); // 자식 6, 자식 없음
    
    root->children[1] = createNode(3, 1); // 자식 3, 자식 1개
    root->children[1]->children[0] = createNode(7, 0); // 자식 7, 자식 없음
    
    root->children[2] = createNode(4, 1); // 자식 4, 자식 1개
    root->children[2]->children[0] = createNode(8, 0); // 자식 8, 자식 없음
    
    root->children[3] = createNode(5, 1); // 자식 5, 자식 1개
    root->children[3]->children[0] = createNode(9, 0); // 자식 9, 자식 없음
    
    return root;
}

// 테스트 케이스 8: 모든 노드가 한 레벨에 있는 경우
// Input: [1,null,2,3,4,5]
// Expected Output: 2
Node* buildTestCase8() {
    Node* root = createNode(1, 4); // 루트 노드 1, 자식 4개
    root->children[0] = createNode(2, 0); // 자식 2, 자식 없음
    root->children[1] = createNode(3, 0); // 자식 3, 자식 없음
    root->children[2] = createNode(4, 0); // 자식 4, 자식 없음
    root->children[3] = createNode(5, 0); // 자식 5, 자식 없음
    return root;
}

// 테스트 케이스 9: 복잡한 트리
// Input: [1,null,2,3,4,5,null,6,7,null,8,9,10,null,11]
// Expected Output: 4
Node* buildTestCase9() {
    Node* root = createNode(1, 2); // 루트 노드 1, 자식 2개
    root->children[0] = createNode(2, 2); // 자식 2, 자식 2개
    root->children[1] = createNode(3, 1); // 자식 3, 자식 1개
    
    root->children[0]->children[0] = createNode(6, 1); // 자식 6, 자식 1개
    root->children[0]->children[1] = createNode(7, 0); // 자식 7, 자식 없음
    
    root->children[1]->children[0] = createNode(8, 1); // 자식 8, 자식 1개
    root->children[1]->children[0]->children[0] = createNode(9, 1); // 자식 9, 자식 1개
    root->children[1]->children[0]->children[0]->children[0] = createNode(10, 0); // 자식 10, 자식 없음
    
    // 자식 6의 자식 11 추가
    root->children[0]->children[0]->children[0] = createNode(11, 0); // 자식 11, 자식 없음
    
    return root;
}

// 테스트 케이스 10: 큰 트리
// Input: [1,null,2,3,4,5,6,7,8,9,10,11,12,13,14]
// Expected Output: 3
Node* buildTestCase10() {
    Node* root = createNode(1, 1); // 루트 노드 1, 자식 1개
    root->children[0] = createNode(2, 3); // 자식 2, 자식 3개
    root->children[0]->children[0] = createNode(3, 1); // 자식 3, 자식 1개
    root->children[0]->children[1] = createNode(4, 1); // 자식 4, 자식 1개
    root->children[0]->children[2] = createNode(5, 1); // 자식 5, 자식 1개
    
    root->children[0]->children[0]->children[0] = createNode(6, 1); // 자식 6, 자식 1개
    root->children[0]->children[0]->children[0]->children[0] = createNode(7, 0); // 자식 7, 자식 없음
    
    root->children[0]->children[1]->children[0] = createNode(8, 1); // 자식 8, 자식 1개
    root->children[0]->children[1]->children[0]->children[0] = createNode(9, 0); // 자식 9, 자식 없음
    
    root->children[0]->children[2]->children[0] = createNode(10, 2); // 자식 10, 자식 2개
    root->children[0]->children[2]->children[0]->children[0] = createNode(11, 0); // 자식 11, 자식 없음
    root->children[0]->children[2]->children[0]->children[1] = createNode(12, 1); // 자식 12, 자식 1개
    root->children[0]->children[2]->children[0]->children[1]->children[0] = createNode(13, 0); // 자식 13, 자식 없음
    root->children[0]->children[2]->children[0]->children[1]->children[1] = createNode(14, 0); // 자식 14, 자식 없음
    
    return root;
}

// 테스트를 위한 헬퍼 함수
void runTestCase(int testNum, Node* root, int expected) {
    int result = maxDepth(root);
    printf("Test Case %d:\n", testNum);
    printf("Expected Output: %d\n", expected);
    printf("Actual Output:   %d\n", result);
    if (result == expected) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
    printf("----------------------------------------\n");
}

// 메인 함수: 솔루션 테스트
int main() {
    // 테스트 케이스 1
    Node* test1 = buildTestCase1();
    runTestCase(1, test1, 3);
    freeNode(test1);
    
    // 테스트 케이스 2
    Node* test2 = buildTestCase2();
    runTestCase(2, test2, 5);
    freeNode(test2);
    
    // 테스트 케이스 3: 단일 노드
    Node* test3 = buildTestCase3();
    runTestCase(3, test3, 1);
    freeNode(test3);
    
    // 테스트 케이스 4: 빈 트리
    Node* test4 = buildTestCase4();
    runTestCase(4, test4, 0);
    // test4은 NULL이므로 해제할 필요 없음
    
    // 테스트 케이스 5: 두 레벨
    Node* test5 = buildTestCase5();
    runTestCase(5, test5, 2);
    freeNode(test5);
    
    // 테스트 케이스 6: 깊은 트리
    Node* test6 = buildTestCase6();
    runTestCase(6, test6, 5);
    freeNode(test6);
    
    // 테스트 케이스 7: 여러 브랜치
    Node* test7 = buildTestCase7();
    runTestCase(7, test7, 4);
    freeNode(test7);
    
    // 테스트 케이스 8: 모든 노드가 한 레벨에 있는 경우
    Node* test8 = buildTestCase8();
    runTestCase(8, test8, 2);
    freeNode(test8);
    
    // 테스트 케이스 9: 복잡한 트리
    Node* test9 = buildTestCase9();
    runTestCase(9, test9, 4);
    freeNode(test9);
    
    // 테스트 케이스 10: 큰 트리
    Node* test10 = buildTestCase10();
    runTestCase(10, test10, 3);
    freeNode(test10);
    
    return 0;
}
