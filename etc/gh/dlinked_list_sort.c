#include <stdio.h>
#include <stdlib.h>

typedef struct LLNode {
    int val;
    struct LLNode *prv, *nxt;
} LLNode;

void print_linked_list (LLNode *head) {
    LLNode *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->nxt;
    }
printf("\n");
}


void swap_cur_next(LLNode *cur){
    int temp = cur->val;
    cur->val = cur->nxt->val;
    cur->nxt->val = temp;
}

void sort_list(LLNode *head){
    int count = 0;
    LLNode *cur = head;
    //총 몇개인지 count
    while (cur->nxt != NULL){
        count ++;
        cur = cur->nxt;
    }

    
    for(int i = 0 ; i < count ; i++){
        cur = head;
        for(int j = 0 ; j < count ; j++){
            if (cur->val > cur->nxt->val) swap_cur_next(cur);
            cur = cur->nxt;
        }
    }

    //

}

void sort_each_list(LLNode *head_list[], int num){
    for(int i = 0 ; i < num ; i ++){
        sort_list(head_list[i]);
    }
}

LLNode* merge_sorted_lists(LLNode *head[], int num){

    LLNode *current[100];
    for (int i = 0; i < num; i++) {
        current[i] = head[i];
    }

    LLNode *new_head = NULL;
    LLNode *new_tail = NULL;

    while (1) {
        // 현재 노드들 중 가장 작은 값을 찾음
        int min_index = -1;
        for (int i = 0; i < num; i++) {
            if (current[i] != NULL) {
                if (min_index == -1 || current[i]->val < current[min_index]->val) {
                    min_index = i;
                }
            }
        }

        // 더 이상 노드가 남아있지 않으면 종료
        if (min_index == -1) {
            break;
        }

        // 새로운 노드 생성 또는 연결
        if (new_head == NULL) {
            new_head = current[min_index];
            new_tail = new_head;
        } else {
            new_tail->nxt = current[min_index];
            current[min_index]->prv = new_tail;
            new_tail = new_tail->nxt;
        }

        // 선택된 리스트의 포인터를 다음 노드로 이동
        current[min_index] = current[min_index]->nxt;
    }

    // 모든 리스트 병합 후, 마지막 노드의 nxt를 NULL로 설정
    if (new_tail != NULL) {
        new_tail->nxt = NULL;
    }

    return new_head;
}

int main () {
    LLNode *node11 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node12 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node13 = (LLNode *) malloc(sizeof(LLNode));
    node11->val = 3; node11->nxt = node12, node11->prv = NULL;
    node12->val = 1; node12->nxt = node13, node12->prv = node11;
    node13->val = 5; node13->nxt = NULL, node13->prv = node12;
    LLNode *list1 = node11;
    LLNode *node21 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node22 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node23 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node24 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node25 = (LLNode *) malloc(sizeof(LLNode));
    node21->val = 2; node21->nxt = node22, node21->prv = NULL;
    node22->val = 8; node22->nxt = node23, node22->prv = node21;
    node23->val = 6; node23->nxt = node24, node23->prv = node22;
    node24->val = 1; node24->nxt = node25, node24->prv = node23;
    node25->val = 1; node25->nxt = NULL, node25->prv = node24;
    LLNode *list2 = node21;
    LLNode *node31 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node32 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node33 = (LLNode *) malloc(sizeof(LLNode));
    LLNode *node34 = (LLNode *) malloc(sizeof(LLNode));
    node31->val = 7; node31->nxt = node32, node31->prv = NULL;
    node32->val = 2; node32->nxt = node33, node32->prv = node31;
    node33->val = 7; node33->nxt = node34, node33->prv = node32;
    node34->val = 4; node34->nxt = NULL, node34->prv = node33;
    LLNode *list3 = node31;
    print_linked_list(list1);
    print_linked_list(list2);
    print_linked_list(list3);
    sort_list(list1);
    print_linked_list(list1);
    LLNode *lists[100];
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;
    sort_each_list(lists, 3);
    print_linked_list(list1);
    print_linked_list(list2);
    print_linked_list(list3);
    //LLNode *merged = merge_sorted_lists(lists, 3);
    //print_linked_list(merged);
    return 0;
}