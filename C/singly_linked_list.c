#include <stdio.h>
#include <stdlib.h>

// LinkedNode 구조체 정의
typedef struct nodeType LinkedNode;
struct nodeType {
    int val;
    LinkedNode *next;
};

// SLList 구조체 정의
typedef struct listType SLList;
struct listType {
    LinkedNode *first; // 첫 번째 LinkedNode를 추적
    int size;          // 리스트의 크기를 추적
};

// x 값을 갖는 새로운 노드를 생성하는 함수
LinkedNode *createNode(int x) {
    LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

// 리스트의 앞에 새로운 노드를 추가하는 함수
void addFirst(SLList *LL, int x) {
    LinkedNode *newFirst = createNode(x);
    newFirst->next = LL->first;
    LL->first = newFirst;
    LL->size++;
}

// 첫 번째 노드의 값을 반환하는 함수
int getFirst(SLList *LL) {
    if (LL->first != NULL) {
        return LL->first->val;
    }
    return 0; // 리스트가 비어 있을 경우 0 반환 (아무 의미 없는 값)
}

// 리스트의 크기를 반환하는 함수
int getSize(SLList *LL) {
    return LL->size;
}

// 리스트의 모든 요소를 출력하는 함수
void printSLList(SLList *LL) {
    LinkedNode *curr = LL->first;
    printf("size: %d, firstVal: %d, allVals: ", getSize(LL), getFirst(LL));
    while (curr != NULL) {
        printf("%d->", curr->val);
        curr = curr->next;
    }
    printf("END\n");
}

// 특정 값을 갖는 노드를 검색하는 함수
LinkedNode *searchNode(SLList *LL, int x) {
    LinkedNode *curr = LL->first;
    while (curr != NULL) {
        if (curr->val == x) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL; // 찾지 못한 경우 NULL 반환
}

// 특정 값을 갖는 노드를 삭제하는 함수
void deleteNode(SLList *LL, int x) {
    LinkedNode *curr = LL->first;
    LinkedNode *prev = NULL;

    while (curr != NULL) {
        if (curr->val == x) {
            // 첫 번째 노드를 삭제하는 경우
            if (curr == LL->first) {
                LL->first = LL->first->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            LL->size--;
            return;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main(void) {
    SLList myLL = {NULL, 0}; // 빈 SLList 생성
    addFirst(&myLL, 10); // myLL에 10을 추가
    printf("%d\n", getFirst(&myLL)); // 첫 번째 val을 출력
    getSize(&myLL); // size를 출력
    printSLList(&myLL); // myLL 전체를 출력

    SLList myLL2 = {NULL, 0}; // 빈 리스트 생성
    printSLList(&myLL2);
    // size: 0, firstVal: 0, allVals: END

    addFirst(&myLL, 10);
    printSLList(&myLL);
    // size: 1, firstVal: 10, allVals: 10->END

    addFirst(&myLL, 20);
    printSLList(&myLL);
    // size: 2, firstVal: 20, allVals: 20->10->END

    addFirst(&myLL, 30);
    printSLList(&myLL);
    // size: 3, firstVal: 30, allVals: 30->20->10->END

    deleteNode(&myLL, 20);
    printSLList(&myLL);
    // size: 2, firstVal: 30, allVals: 30->10->END

    deleteNode(&myLL, 30);
    printSLList(&myLL);
    // size: 1, firstVal: 10, allVals: 10->END

    return 0;
}
