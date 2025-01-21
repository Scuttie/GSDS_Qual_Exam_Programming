#include <stdio.h>
#include <stdlib.h>

// ------------------ Stack 구조체와 관련 함수 ------------------
typedef struct Stack {
    int *data;       // 실제 데이터를 저장할 배열
    int top;         // 스택의 최상단 인덱스
    int capacity;    // 스택의 최대 용량
} Stack;

// 스택 생성 함수
Stack* create_stack(int capacity) {
    Stack *newStack = (Stack*)malloc(sizeof(Stack));
    newStack->data = (int*)malloc(sizeof(int) * capacity);
    newStack->top = -1;
    newStack->capacity = capacity;
    return newStack;
}

// 스택이 비었는지 확인
int is_empty(Stack *st) {
    return (st->top == -1);
}

// 스택이 가득 찼는지 확인
int is_full(Stack *st) {
    return (st->top == st->capacity - 1);
}

// 스택에 push
void push_stack(Stack *st, int val) {
    if (!is_full(st)) {
        st->top++;
        st->data[st->top] = val;
    }
}

// 스택에서 pop
int pop_stack(Stack *st) {
    if (!is_empty(st)) {
        int val = st->data[st->top];
        st->top--;
        return val;
    }
    // 비어 있다면 예외 처리 (여기선 -9999 반환)
    return -9999;
}

// ------------------ ListNode 구조체와 관련 함수 ------------------
typedef struct ListNode {
    struct Stack *stack;
    struct ListNode *next;
    int stack_capacity; // 각 노드(스택)의 용량(문제 요구사항에 따라)
} ListNode;

// 리스트 전체에 몇 개의 스택 노드가 있는지 세는 함수
int list_size(ListNode *head) {
    // head가 NULL이거나 스택이 하나도 없을 수도 있으므로 체크
    if (head == NULL || head->stack == NULL) {
        return 0;
    }

    int count = 0;
    ListNode *curr = head;
    while (curr != NULL) {
        if (curr->stack != NULL) {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

// 리스트의 마지막 노드를 찾아 반환 (head가 비어있을 때 대비)
ListNode* get_last_node(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}

// 리스트의 push 함수
void push_los(ListNode *head, int val) {
    // 만약 head 자체가 없으면(예외 케이스), 그냥 리턴 혹은 처리
    if (head == NULL) return;

    // head->stack이 NULL이면(아직 스택이 없는 경우) 새 스택을 생성
    if (head->stack == NULL) {
        head->stack = create_stack(head->stack_capacity);
    }

    // 마지막 노드를 찾는다
    ListNode *last = get_last_node(head);

    // 해당 노드의 스택이 가득 찼으면 새 노드를 만들어 연결
    if (is_full(last->stack)) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->stack = create_stack(head->stack_capacity);
        newNode->stack_capacity = head->stack_capacity;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode; // 이제 last를 새 노드로 갱신
    }

    // 마지막 노드의 스택에 push
    push_stack(last->stack, val);
}

// 리스트의 pop 함수
int pop_los(ListNode *head) {
    // 비어있는 리스트(스택이 전혀 없거나, head 자체가 NULL)라면 -9999 리턴
    if (head == NULL || head->stack == NULL) {
        return -9999;
    }

    // 마지막 노드 탐색
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    // curr가 마지막 노드

    // 마지막 노드의 스택에서 pop
    int val = pop_stack(curr->stack);
    if (val == -9999) {
        // 스택이 비어 pop을 못 했다는 뜻 -> 이미 빈 스택이라는 의미
        return -9999;
    }

    // pop 후 해당 스택이 비었으면 노드 제거
    if (is_empty(curr->stack)) {
        // 리스트에 노드가 1개인 경우
        if (curr == head) {
            // head 노드뿐이므로 head->stack만 해제하고 재사용 가능
            free(curr->stack->data);
            free(curr->stack);
            curr->stack = NULL;
        } else {
            // 마지막 노드를 지우고 이전 노드의 next를 NULL로
            free(curr->stack->data);
            free(curr->stack);
            free(curr);
            prev->next = NULL;
        }
    }

    return val;
}

// ------------------ main 함수 ------------------
int main() {
    // head 노드 생성
    ListNode *head = (ListNode*) malloc(sizeof(ListNode));
    head->next = NULL;
    head->stack = NULL;        // 아직 스택 미생성
    head->stack_capacity = 3;  // 문제에서 예시로 3

    // 테스트
    printf("list_size: %d\n", list_size(head));  // 현재 스택이 없으므로 0

    push_los(head, 10);
    push_los(head, 5);
    push_los(head, 4);

    // 이제 스택 1개가 생겼고, 총 3개를 push 했으므로 아직 1개의 스택만 존재
    printf("list_size: %d\n", list_size(head));

    // 스택 용량은 3이고 이미 3개가 들어있으므로 다음 push 시 새 노드 생성
    push_los(head, 18);
    printf("list_size: %d\n", list_size(head));  // 스택 노드가 2개

    // pop 2번
    printf("pop: %d\n", pop_los(head));  // 18
    printf("pop: %d\n", pop_los(head));  // 4 (이전 스택으로 넘어가서 pop)

    // 이제 1번 스택에는 [10,5]가 남음(top이 1). 두 번째 스택은 비었으므로 제거됐을 것
    printf("list_size: %d\n", list_size(head));  // 다시 1개 노드만 남음

    // 이어서 pop 3번
    printf("pop: %d\n", pop_los(head));  // 5
    printf("pop: %d\n", pop_los(head));  // 10
    printf("pop: %d\n", pop_los(head));  // -9999 (더 이상 비어 있으니 pop 불가)

    printf("list_size: %d\n", list_size(head));  // 0 (head는 남아 있으나 스택은 없음)

    // 동적 할당 해제(예시에선 head만 생성했으므로 head만 해제)
    // 실제 개발 시 list 전체를 해제하는 함수를 추가하여 마무리하는 것이 좋다.
    free(head);

    return 0;
}
