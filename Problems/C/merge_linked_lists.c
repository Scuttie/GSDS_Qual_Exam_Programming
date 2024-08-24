//서로 다른 두개의 같은 크기의 Linked List를 Merge하는 코드입니다.
//ex) 2 -> 3 -> 4 & 1 -> 5 -> 7의 경우 1 -> 2 -> 3 -> 4 -> 5 -> 7로 Merge
//tail Node pointer를 관리해서, 각 step마다 두 Linked List의 크기를 비교하면서 정렬하는 것이 주요합니다.

#include<stdio.h>
#include<stdlib.h>

/* Linked list node structure */

struct Node
{
    int data;
    struct Node* next;
};


struct Node* mergeTwoLists(struct Node* a, struct Node* b) {
    struct Node dummy; // 더미 노드 생성
    struct Node* tail = &dummy; // tail은 dummy의 주소를 참조함 (마지막 주소)
    dummy.next = NULL; // 더미 노드 초기화

    //a와 b가 둘다 NULL이 아닐때까지
    while (a != NULL && b != NULL) {
        // 데이터 비교
        if (a->data <= b->data) {
            tail->next = a; // a가 작으면 tail의 next를 a로 (가장 마지막에서 하나씩 작은걸 추가) 
            a = a->next; // a를 다음으로 넘어감
        } 
        // 반대 경우도 똑같이 핸들링
        else {
            tail->next = b;
            b = b->next;
        }
        // 다 끝나면 tail을 다음으로 넘김
        tail = tail->next;
    }

    // 위의 반복문이 종료됐을 때, 특정 linkedlist는 남아있는 원소가 있을 수 있음.
    // a가 남을 경우 tail -> next를 a로, 반대의 경우는 반대로 하면 남아있는 원소를 반영 할 수 있음.
    if (a != NULL) {
        tail->next = a;
    } else {
        tail->next = b;
    }

    // dummy.next에 첫번째 Node가 저장돼있으므로 반환
    return dummy.next;
}
    // DO NOT MODIFY BELOW

/* Function to create a new node */
struct Node * createNode(int x){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}
typedef struct listType SLList;
struct listType{
    struct Node *first;
    int size;
};

void addFirst(SLList *LL, int x);

int main(int argc, char* argv[]){
    SLList list_a = {NULL, 0};
    SLList list_b = {NULL, 0};
    for(int i = 0; i < (argc-1)/2; i++)
        addFirst(&list_a, atoi(argv[(argc-1)/2-i])); 

    for(int i = 0; i < argc/2; i++){
        addFirst(&list_b, atoi(argv[(argc-1)-i]));
        }
    struct Node *c;
    c =  mergeTwoLists(list_a.first, list_b.first);
    // print mergeed lists
    while (c){
        printf("%d ", c ->data);
        c = c->next;
    }
    
}

void addFirst(SLList *LL, int x){
    struct Node *newFirst;
    newFirst = createNode(x);
    newFirst -> next = LL -> first;
    LL -> first = newFirst;
    LL -> size++;
}
