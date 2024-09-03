#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int is_full(Stack* stack) {
    return stack->top == MAX - 1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (is_full(stack))
        return;
    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (is_empty(stack))
        return INT_MIN;
    return stack->items[stack->top--];
}

int peek(Stack* stack) {
    if (is_empty(stack))
        return INT_MIN;
    return stack->items[stack->top];
}

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    printf("%d popped from stack\n", pop(stack));  // 출력: 20 popped from stack
    printf("Top element is %d\n", peek(stack));    // 출력: Top element is 10
    return 0;
}
