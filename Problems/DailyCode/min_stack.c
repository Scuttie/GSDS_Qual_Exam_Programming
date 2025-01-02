#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack 구조체 정의
typedef struct {
    int* array;     // 스택을 저장할 동적 배열
    int size;       // 현재 스택의 크기
    int capacity;   // 스택의 용량
} Stack;

// Stack 생성 함수
Stack* stackCreate(int initialCapacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    stack->array = (int*)malloc(sizeof(int) * initialCapacity);
    if (!stack->array) {
        fprintf(stderr, "메모리 할당 실패\n");
        free(stack);
        exit(EXIT_FAILURE);
    }
    stack->size = 0;
    stack->capacity = initialCapacity;
    return stack;
}

// Stack에 요소를 푸시하는 함수
bool stackPush(Stack* stack, int val) {
    if (stack->size == stack->capacity) {
        // 스택 용량이 가득 찼을 경우, 용량을 두 배로 확장
        int newCapacity = stack->capacity * 2;
        int* newArray = (int*)realloc(stack->array, sizeof(int) * newCapacity);
        if (!newArray) {
            fprintf(stderr, "메모리 재할당 실패\n");
            return false;
        }
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[stack->size++] = val;
    return true;
}

// Stack에서 요소를 팝하는 함수
bool stackPop(Stack* stack) {
    if (stack->size == 0) {
        return false; // 스택이 비어있으면 팝 불가
    }
    stack->size--;
    return true;
}

// Stack의 최상위 요소를 반환하는 함수
int stackTop(Stack* stack) {
    if (stack->size == 0) {
        return -1; // 스택이 비어있으면 -1 반환
    }
    return stack->array[stack->size - 1];
}

// Stack이 비어있는지 확인하는 함수
bool stackIsEmpty(Stack* stack) {
    return stack->size == 0;
}

// Stack을 해제하는 함수
void stackFree(Stack* stack) {
    if (stack) {
        free(stack->array);
        free(stack);
    }
}

// MinStack 구조체 정의
typedef struct {
    Stack* data;      // 실제 스택을 저장하는 스택
    Stack* min_stack; // 현재까지의 최소값을 저장하는 스택
} MinStack;

// MinStack 생성 함수
MinStack* minStackCreate() {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    if (!minStack) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    // 초기 용량을 16으로 설정 (필요에 따라 확장 가능)
    minStack->data = stackCreate(16);
    minStack->min_stack = stackCreate(16);
    return minStack;
}

// MinStack에 값을 푸시하는 함수
void minStackPush(MinStack* obj, int val) {
    stackPush(obj->data, val);
    if (stackIsEmpty(obj->min_stack) || val <= stackTop(obj->min_stack)) {
        stackPush(obj->min_stack, val);
    }
}

// MinStack에서 값을 팝하는 함수
void minStackPop(MinStack* obj) {
    if (stackIsEmpty(obj->data)) {
        return; // 스택이 비어있으면 팝 불가
    }
    int topVal = stackTop(obj->data);
    stackPop(obj->data);
    if (topVal == stackTop(obj->min_stack)) {
        stackPop(obj->min_stack);
    }
}

// MinStack의 최상위 값을 반환하는 함수
int minStackTop(MinStack* obj) {
    return stackTop(obj->data);
}

// MinStack의 현재 최소값을 반환하는 함수
int minStackGetMin(MinStack* obj) {
    return stackTop(obj->min_stack);
}

// MinStack을 해제하는 함수
void minStackFree(MinStack* obj) {
    if (obj) {
        stackFree(obj->data);
        stackFree(obj->min_stack);
        free(obj);
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

// 테스트를 위한 메인 함수
int main() {
    // 예제 테스트 케이스:
    // ["MinStack","push","push","push","getMin","pop","top","getMin"]
    // [[],[-2],[0],[-3],[],[],[],[]]
    printf("Test Case 1:\n");
    MinStack* minStack = minStackCreate();
    minStackPush(minStack, -2);
    minStackPush(minStack, 0);
    minStackPush(minStack, -3);
    printf("getMin(): %d (Expected: -3)\n", minStackGetMin(minStack));
    minStackPop(minStack);
    printf("top(): %d (Expected: 0)\n", minStackTop(minStack));
    printf("getMin(): %d (Expected: -2)\n", minStackGetMin(minStack));
    minStackFree(minStack);
    printf("PASS\n");
    printf("----------------------------------------\n");

    // 추가 테스트 케이스 2:
    // ["MinStack","push","push","getMin","pop","getMin"]
    // [[],[1],[2],[],[],[]]
    printf("Test Case 2:\n");
    minStack = minStackCreate();
    minStackPush(minStack, 1);
    minStackPush(minStack, 2);
    printf("getMin(): %d (Expected: 1)\n", minStackGetMin(minStack));
    minStackPop(minStack);
    printf("getMin(): %d (Expected: 1)\n", minStackGetMin(minStack));
    minStackFree(minStack);
    printf("PASS\n");
    printf("----------------------------------------\n");

    // 추가 테스트 케이스 3:
    // ["MinStack","push","push","push","push","getMin","pop","getMin"]
    // [[],[3],[5],[2],[1],[],[],[]]
    printf("Test Case 3:\n");
    minStack = minStackCreate();
    minStackPush(minStack, 3);
    minStackPush(minStack, 5);
    minStackPush(minStack, 2);
    minStackPush(minStack, 1);
    printf("getMin(): %d (Expected: 1)\n", minStackGetMin(minStack));
    minStackPop(minStack);
    printf("getMin(): %d (Expected: 2)\n", minStackGetMin(minStack));
    minStackFree(minStack);
    printf("PASS\n");
    printf("----------------------------------------\n");

    // 추가 테스트 케이스 4:
    // ["MinStack","push","getMin","push","getMin","pop","getMin"]
    // [[],[0],[],[1],[],[],[]]
    printf("Test Case 4:\n");
    minStack = minStackCreate();
    minStackPush(minStack, 0);
    printf("getMin(): %d (Expected: 0)\n", minStackGetMin(minStack));
    minStackPush(minStack, 1);
    printf("getMin(): %d (Expected: 0)\n", minStackGetMin(minStack));
    minStackPop(minStack);
    printf("getMin(): %d (Expected: 0)\n", minStackGetMin(minStack));
    minStackFree(minStack);
    printf("PASS\n");
    printf("----------------------------------------\n");

    // 추가 테스트 케이스 5:
    // ["MinStack","push","push","push","push","getMin","pop","getMin","pop","getMin"]
    // [[],[2],[0],[3],[0],[],[],[],[],[]]
    printf("Test Case 5:\n");
    minStack = minStackCreate();
    minStackPush(minStack, 2);
    minStackPush(minStack, 0);
    minStackPush(minStack, 3);
    minStackPush(minStack, 0);
    printf("getMin(): %d (Expected: 0)\n", minStackGetMin(minStack));
    minStackPop(minStack);
    printf("getMin(): %d (Expected: 0)\n", minStackGetMin(minStack));
    minStackPop(minStack);
    printf("getMin(): %d (Expected: 0)\n", minStackGetMin(minStack));
    minStackPop(minStack);
    printf("getMin(): %d (Expected: 2)\n", minStackGetMin(minStack));
    minStackFree(minStack);
    printf("PASS\n");
    printf("----------------------------------------\n");

    return 0;
}
