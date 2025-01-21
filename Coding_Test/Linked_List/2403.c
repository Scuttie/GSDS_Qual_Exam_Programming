#include <stdio.h>
#include <stdlib.h>

typedef struct LLNode {
    int val;
    struct LLNode *prv, *nxt;
} LLNode;

void sort_list(LLNode *head) {
    if (head == NULL || head->nxt == NULL) {
        return;  // 노드가 0개 또는 1개면 이미 정렬된 상태
    }

    int swapped;
    LLNode *current;

    do {
        swapped = 0;
        current = head;

        // 리스트를 순회하며 인접 원소 비교 후 교환
        while (current->nxt != NULL) {
            if (current->val > current->nxt->val) {
                // 두 노드 값 교환 (노드 포인터를 재배치하는 대신 값만 스왑)
                int temp = current->val;
                current->val = current->nxt->val;
                current->nxt->val = temp;
                swapped = 1;
            }
            current = current->nxt;
        }
        // 한 번의 패스가 끝난 뒤 swapped가 0이면 이미 정렬 완료
    } while (swapped);
}

void sort_each_list(LLNode *head[100], int N) {
    for (int i = 0; i < N; i++) {
        sort_list(head[i]);
    }
}

// 이중 연결 리스트 뒤집기 함수
LLNode* reverse_dll(LLNode *head) {
    LLNode *cur = head;
    LLNode *temp = NULL;
    
    // cur을 순회하면서 prv, nxt를 뒤집는다
    while (cur != NULL) {
        temp = cur->prv;
        cur->prv = cur->nxt;
        cur->nxt = temp;
        cur = cur->prv;
    }
    // temp는 마지막으로 방문한 노드를 가리키고 있으므로,
    // temp가 NULL이 아니라면 temp->prv가 새 헤드
    if (temp != NULL) {
        head = temp->prv;
    }
    return head;
}

// 여러 개의 정렬된(오름차순) 이중 연결 리스트를 머지하여
// 내림차순으로 정렬된 한 개의 이중 연결 리스트를 반환
LLNode* merge_sorted_lists(LLNode *head[100], int N) {
    // 결과 리스트를 담을 더미(dummy) 노드 생성
    LLNode dummy;
    dummy.nxt = NULL; 
    dummy.prv = NULL;
    
    LLNode *tail = &dummy;  // 결과 리스트의 끝을 가리킬 포인터

    int emptyCount = 0; // 몇 개의 리스트가 끝에 도달했는지(모두 합쳐질 때까지 반복)
    
    // 모든 리스트가 빌 때까지 반복
    while (1) {
        // 모든 head[i]가 NULL인지 확인
        int allNull = 1;
        for (int i = 0; i < N; i++) {
            if (head[i] != NULL) {
                allNull = 0;
                break;
            }
        }
        if (allNull) {
            break;  // 모든 리스트가 소진됨
        }
        
        // 1) 현재 유효한 head[i] 중 값이 가장 작은 노드를 찾는다
        int minIndex = -1;
        int minValue = 0;  // 비교를 위한 임시 값
        for (int i = 0; i < N; i++) {
            if (head[i] != NULL) {
                if (minIndex == -1 || head[i]->val < minValue) {
                    minValue = head[i]->val;
                    minIndex = i;
                }
            }
        }
        
        // 2) minIndex에서 노드 하나를 떼어 결과 리스트의 뒤에 붙인다
        LLNode *picked = head[minIndex];      // 머지할 노드
        head[minIndex] = head[minIndex]->nxt; // 해당 리스트 헤드 이동
        
        // 원래 리스트에서 떼어냈으니 포인터 재설정
        if (head[minIndex] != NULL) {
            head[minIndex]->prv = NULL;
        }
        
        // 결과 리스트 연결
        picked->nxt = NULL;
        picked->prv = tail == &dummy ? NULL : tail; // dummy 다음이라면 prv=NULL
        tail->nxt = picked;
        tail = picked;
    }
    
    // 이제 dummy.nxt부터가 "오름차순"으로 정렬된 리스트
    // 이를 뒤집어 "내림차순" 리스트로 만든다
    LLNode *mergedHead = dummy.nxt;
    if (mergedHead != NULL) {
        mergedHead->prv = NULL; // 더미 뒤쪽이 새 헤드
    }
    
    // 리스트 뒤집기
    mergedHead = reverse_dll(mergedHead);
    
    return mergedHead; // 내림차순 정렬된 리스트의 헤드 반환
}

int main () {
    // 노드 생성 및 연결(list1)
    LLNode *node11 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node12 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node13 = (LLNode *) malloc(sizeof(LLNode));
    node11->val = 3; node11->nxt = node12; node11->prv = NULL;
    node12->val = 1; node12->nxt = node13; node12->prv = node11;
    node13->val = 5; node13->nxt = NULL;   node13->prv = node12;
    LLNode *list1 = node11;
    
    // 노드 생성 및 연결(list2)
    LLNode *node21 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node22 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node23 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node24 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node25 = (LLNode *) malloc(sizeof(LLNode));
    node21->val = 2;  node21->nxt = node22; node21->prv = NULL;
    node22->val = 8;  node22->nxt = node23; node22->prv = node21;
    node23->val = 6;  node23->nxt = node24; node23->prv = node22;
    node24->val = 1;  node24->nxt = node25; node24->prv = node23;
    node25->val = 1;  node25->nxt = NULL;   node25->prv = node24;
    LLNode *list2 = node21;
    
    // 노드 생성 및 연결(list3)
    LLNode *node31 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node32 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node33 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node34 = (LLNode *) malloc(sizeof(LLNode));
    node31->val = 7;  node31->nxt = node32; node31->prv = NULL;
    node32->val = 2;  node32->nxt = node33; node32->prv = node31;
    node33->val = 7;  node33->nxt = node34; node33->prv = node32;
    node34->val = 4;  node34->nxt = NULL;   node34->prv = node33;
    LLNode *list3 = node31;
    
    // 출력 함수
    void print_linked_list(LLNode *head) {
        LLNode *cur = head;
        while (cur != NULL) {
            printf("%d ", cur->val);
            cur = cur->nxt;
        }
        printf("\n");
    }
    
    // 초기 리스트 상태 출력
    print_linked_list(list1);  // 3 1 5
    print_linked_list(list2);  // 2 8 6 1 1
    print_linked_list(list3);  // 7 2 7 4
    
    // (1) 단일 리스트 정렬 (오름차순)
    sort_list(list1);
    print_linked_list(list1);  // 1 3 5 (정렬 완료)
    
    // (2) 모든 리스트를 오름차순 정렬
    LLNode *lists[100];
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;
    sort_each_list(lists, 3);
    print_linked_list(list1);  // 1 3 5
    print_linked_list(list2);  // 1 1 2 6 8
    print_linked_list(list3);  // 2 4 7 7
    
    // (3) 여러 정렬된 리스트를 하나로 머지(내림차순)
    LLNode *merged = merge_sorted_lists(lists, 3);
    print_linked_list(merged); // 8 7 7 6 5 4 3 2 2 1 1 1
    
    // 동적 할당된 노드는 테스트 후 필요 시 free() 처리
    return 0;
}

