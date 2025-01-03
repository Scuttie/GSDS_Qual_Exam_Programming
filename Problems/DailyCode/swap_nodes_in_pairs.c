#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;                // 노드의 값
    struct ListNode *next;  // 다음 노드를 가리키는 포인터
};

/**
 * Helper function to create a new ListNode.
 * 
 * @param val 노드에 저장할 값
 * @return 새로 생성된 ListNode의 포인터
 */
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) {
        printf("메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

/**
 * Helper function to create a linked list from an array of integers.
 * 
 * @param arr 정수 배열
 * @param size 배열의 크기
 * @return 생성된 linked list의 헤드 노드 포인터
 */
struct ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;  // 빈 배열일 경우 NULL 반환

    struct ListNode* head = createNode(arr[0]);  // 첫 번째 노드 생성
    struct ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);  // 다음 노드 생성 및 연결
        current = current->next;
    }

    return head;
}

/**
 * Helper function to print the linked list.
 * 
 * @param head linked list의 헤드 노드 포인터
 */
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    printf("[");
    while (current) {
        printf("%d", current->val);
        if (current->next) printf(",");  // 마지막 노드가 아닐 경우 콤마 추가
        current = current->next;
    }
    printf("]\n");
}

/**
 * Helper function to free the memory allocated for the linked list.
 * 
 * @param head linked list의 헤드 노드 포인터
 */
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);  // 현재 노드 메모리 해제
    }
}

/**
 * Function to swap every two adjacent nodes in a linked list.
 * 
 * @param head linked list의 헤드 노드 포인터
 * @return 변경된 linked list의 새로운 헤드 노드 포인터
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // 더미 노드를 생성하여 헤드를 가리키게 함으로써 포인터 조작을 단순화
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // 두 개의 노드가 존재하는 동안 반복
    while (prev->next && prev->next->next) {
        // 첫 번째와 두 번째 노드를 지정
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;

        // 노드들 스왑
        prev->next = second;          // 이전 노드가 두 번째 노드를 가리키게 함
        first->next = second->next;   // 첫 번째 노드가 세 번째 노드를 가리키게 함
        second->next = first;         // 두 번째 노드가 첫 번째 노드를 가리키게 함

        // 다음 스왑을 위해 이전 노드를 이동
        prev = first;
    }

    // 변경된 리스트의 헤드를 반환
    return dummy.next;
}

/**
 * Main function to test the swapPairs function with various test cases.
 */
int main() {
    // 예제 1:
    int arr1[] = {1, 2, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    struct ListNode* list1 = createList(arr1, size1);
    printf("예제 1 입력: ");
    printList(list1);
    struct ListNode* swapped1 = swapPairs(list1);
    printf("예제 1 출력: ");
    printList(swapped1);
    freeList(swapped1);

    // 예제 2:
    int arr2[] = {};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    struct ListNode* list2 = createList(arr2, size2);
    printf("예제 2 입력: ");
    printList(list2);
    struct ListNode* swapped2 = swapPairs(list2);
    printf("예제 2 출력: ");
    printList(swapped2);
    freeList(swapped2);

    // 예제 3:
    int arr3[] = {1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    struct ListNode* list3 = createList(arr3, size3);
    printf("예제 3 입력: ");
    printList(list3);
    struct ListNode* swapped3 = swapPairs(list3);
    printf("예제 3 출력: ");
    printList(swapped3);
    freeList(swapped3);

    // 예제 4:
    int arr4[] = {1, 2, 3};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    struct ListNode* list4 = createList(arr4, size4);
    printf("예제 4 입력: ");
    printList(list4);
    struct ListNode* swapped4 = swapPairs(list4);
    printf("예제 4 출력: ");
    printList(swapped4);
    freeList(swapped4);

    return 0;
}
