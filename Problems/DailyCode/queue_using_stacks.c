#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 스택 구조체 정의
typedef struct {
    int* data;      // 스택 데이터를 저장할 배열
    int top;        // 스택의 현재 탑 인덱스
    int capacity;   // 스택의 현재 용량
} Stack;

// 스택 초기화 함수
Stack* stackCreate() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->capacity = 100;                      // 초기 용량 설정
    stack->top = -1;                            // 스택이 비어있음을 나타내기 위해 -1로 초기화
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->data) {
        free(stack);
        return NULL;
    }

    return stack;
}

// 스택에 요소를 추가하는 함수 (Push)
bool stackPush(Stack* stack, int x) {
    if (stack->top + 1 >= stack->capacity) {
        // 스택 용량이 부족할 경우, 용량을 두 배로 확장
        stack->capacity *= 2;
        int* newData = (int*)realloc(stack->data, stack->capacity * sizeof(int));
        if (!newData) return false; // 메모리 재할당 실패 시
        stack->data = newData;
    }
    stack->data[++stack->top] = x; // 탑 인덱스를 증가시키고 요소를 추가
    return true;
}

// 스택에서 요소를 제거하고 반환하는 함수 (Pop)
int stackPop(Stack* stack) {
    if (stack->top == -1) return -1; // 스택이 비어있을 경우
    return stack->data[stack->top--]; // 현재 탑 요소를 반환하고 탑 인덱스를 감소
}

// 스택의 탑 요소를 반환하는 함수 (Peek)
int stackPeek(Stack* stack) {
    if (stack->top == -1) return -1; // 스택이 비어있을 경우
    return stack->data[stack->top];  // 현재 탑 요소를 반환
}

// 스택이 비어있는지 확인하는 함수
bool stackEmpty(Stack* stack) {
    return stack->top == -1;
}

// 스택 메모리를 해제하는 함수
void stackFree(Stack* stack) {
    if (stack) {
        if (stack->data) {
            free(stack->data);
        }
        free(stack);
    }
}

// 큐 구조체 정의: 두 개의 스택을 사용하여 FIFO 큐 구현
typedef struct {
    Stack* stack1; // 큐의 입력 스택
    Stack* stack2; // 큐의 출력 스택
} MyQueue;

/**
 * 큐를 생성하고 초기화하는 함수
 * 
 * @return 초기화된 MyQueue 포인터
 */
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    if (!obj) return NULL;

    obj->stack1 = stackCreate(); // 입력 스택 생성
    obj->stack2 = stackCreate(); // 출력 스택 생성

    if (!obj->stack1 || !obj->stack2) {
        // 스택 생성에 실패하면 할당된 메모리 해제
        if (obj->stack1) stackFree(obj->stack1);
        if (obj->stack2) stackFree(obj->stack2);
        free(obj);
        return NULL;
    }

    return obj;
}

/**
 * 큐에 요소를 추가하는 함수
 * 
 * @param obj 큐 객체
 * @param x 추가할 정수 값
 */
void myQueuePush(MyQueue* obj, int x) {
    if (obj && obj->stack1) {
        stackPush(obj->stack1, x); // 입력 스택에 요소 추가
    }
}

/**
 * 큐에서 요소를 제거하고 반환하는 함수
 * 
 * @param obj 큐 객체
 * @return 제거된 정수 값
 */
int myQueuePop(MyQueue* obj) {
    if (obj && obj->stack2) {
        if (stackEmpty(obj->stack2)) {
            // 출력 스택이 비어있으면 입력 스택에서 출력 스택으로 모든 요소를 이동
            while (!stackEmpty(obj->stack1)) {
                int temp = stackPop(obj->stack1);
                stackPush(obj->stack2, temp);
            }
        }
        return stackPop(obj->stack2); // 출력 스택에서 요소 제거 및 반환
    }
    return -1; // 큐가 비어있을 경우
}

/**
 * 큐의 앞 요소를 반환하는 함수
 * 
 * @param obj 큐 객체
 * @return 큐의 앞에 있는 정수 값
 */
int myQueuePeek(MyQueue* obj) {
    if (obj && obj->stack2) {
        if (stackEmpty(obj->stack2)) {
            // 출력 스택이 비어있으면 입력 스택에서 출력 스택으로 모든 요소를 이동
            while (!stackEmpty(obj->stack1)) {
                int temp = stackPop(obj->stack1);
                stackPush(obj->stack2, temp);
            }
        }
        return stackPeek(obj->stack2); // 출력 스택의 탑 요소 반환
    }
    return -1; // 큐가 비어있을 경우
}

/**
 * 큐가 비어있는지 확인하는 함수
 * 
 * @param obj 큐 객체
 * @return 큐가 비어있으면 true, 아니면 false
 */
bool myQueueEmpty(MyQueue* obj) {
    if (obj) {
        return stackEmpty(obj->stack1) && stackEmpty(obj->stack2); // 두 스택이 모두 비어있어야 큐도 비어있음
    }
    return true; // 큐 객체가 NULL인 경우 비어있다고 간주
}

/**
 * 큐의 메모리를 해제하는 함수
 * 
 * @param obj 큐 객체
 */
void myQueueFree(MyQueue* obj) {
    if (obj) {
        if (obj->stack1) stackFree(obj->stack1); // 입력 스택 메모리 해제
        if (obj->stack2) stackFree(obj->stack2); // 출력 스택 메모리 해제
        free(obj); // 큐 구조체 메모리 해제
    }
}

/**
 * MyQueue 구조체가 다음과 같이 호출될 것임:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */

// 테스트를 위한 메인 함수 (선택 사항)
int main() {
    MyQueue* obj = myQueueCreate();
    if (!obj) {
        printf("큐 생성 실패\n");
        return -1;
    }

    // 예제 1
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    printf("Peek: %d\n", myQueuePeek(obj)); // 출력: 1
    printf("Pop: %d\n", myQueuePop(obj));   // 출력: 1
    printf("Empty: %s\n", myQueueEmpty(obj) ? "true" : "false"); // 출력: false

    // 추가 테스트
    myQueuePush(obj, 3);
    printf("Peek: %d\n", myQueuePeek(obj)); // 출력: 2
    printf("Pop: %d\n", myQueuePop(obj));   // 출력: 2
    printf("Pop: %d\n", myQueuePop(obj));   // 출력: 3
    printf("Empty: %s\n", myQueueEmpty(obj) ? "true" : "false"); // 출력: true

    myQueueFree(obj); // 큐 메모리 해제
    return 0;
}
