#include <stdio.h>
#include <stdlib.h>

// 단일 연결 리스트 노드 구조체 정의
struct ListNode {
    int val;
    struct ListNode *next;
};

// 주어진 연결 리스트를 합산하여 새로운 연결 리스트를 반환하는 함수
struct ListNode* mergeNodes(struct ListNode* head) {
    int sum = 0;  // 현재 구간의 합계를 저장할 변수
    struct ListNode *newNode = head->next;  // 첫 번째 0 이후부터 시작
    struct ListNode *prev = NULL;  // 새로운 리스트의 마지막 노드를 추적
    struct ListNode *prev_head = NULL;  // 새로운 리스트의 첫 노드를 추적

    while (newNode != NULL) {
        if (newNode->val == 0) {
            if (prev == NULL) {
                // 첫 번째 노드를 생성하고 시작
                prev = (struct ListNode*)malloc(sizeof(struct ListNode));
                prev->val = sum;
                prev->next = NULL;
                prev_head = prev;  // 첫 노드를 저장
            } else {
                // 새로운 노드를 생성하여 리스트에 추가
                prev->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                prev = prev->next;
                prev->val = sum;
                prev->next = NULL;
            }
            sum = 0;  // 새로운 구간을 위해 합계를 초기화
        } else {
            sum += newNode->val;  // 현재 노드의 값을 합계에 추가
        }
        newNode = newNode->next;  // 다음 노드로 이동
    }
    return prev_head;  // 새롭게 생성된 리스트의 시작 노드를 반환
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

// 연결 리스트를 출력하는 함수 (도우미 함수)
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// main 함수 - 테스트 케이스 예제
int main() {
    struct ListNode* head = NULL;
    head = addNode(head, 0);
    head = addNode(head, 3);
    head = addNode(head, 1);
    head = addNode(head, 0);
    head = addNode(head, 4);
    head = addNode(head, 5);
    head = addNode(head, 2);
    head = addNode(head, 0);

    struct ListNode* merged = mergeNodes(head);
    printList(merged);

    return 0;
}
