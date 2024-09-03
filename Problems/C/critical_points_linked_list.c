#include <stdio.h>
#include <stdlib.h>

// 단일 연결 리스트 노드 구조체 정의
struct ListNode {
    int val;
    struct ListNode *next;
};

// 임계점의 인덱스를 반환하는 함수
int* findCriticalPoints(struct ListNode* head, int* returnSize) {
    struct ListNode *prev = head;  // 이전 노드를 추적
    head = head->next;  // 현재 노드를 head로 설정 (두 번째 노드)
    int cnt = 1;  // 현재 노드의 인덱스
    int* criticalPoints = (int*)malloc(1000 * sizeof(int));  // 임계점을 저장할 배열 (최대 1000개의 임계점)
    int criticalCount = 0;  // 임계점의 개수를 추적
    
    while (head != NULL && head->next != NULL) {
        cnt++;
        // 임계점인지 확인
        if ((prev->val < head->val && head->next->val < head->val) || 
            (prev->val > head->val && head->next->val > head->val)) {
            criticalPoints[criticalCount++] = cnt;  // 임계점 인덱스 저장
        }
        prev = head;  // 현재 노드를 이전 노드로 갱신
        head = head->next;  // 다음 노드로 이동
    }
    
    *returnSize = criticalCount;  // 임계점의 개수를 반환 크기로 설정
    return criticalPoints;  // 임계점 인덱스 배열 반환
}

// 연결 리스트에 노드 추가 함수 (도우미 함수)
struct ListNode* addNode(struct ListNode* head, int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        return newNode;
    }
    
    struct ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    
    return head;
}

// main 함수 - 테스트 케이스 예제
int main() {
    struct ListNode* head = NULL;
    head = addNode(head, 5);
    head = addNode(head, 3);
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 5);
    head = addNode(head, 1);
    
    int returnSize;
    int* criticalPoints = findCriticalPoints(head, &returnSize);
    
    printf("Critical points indices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", criticalPoints[i]);
    }
    printf("\n");
    
    free(criticalPoints);
    
    return 0;
}
