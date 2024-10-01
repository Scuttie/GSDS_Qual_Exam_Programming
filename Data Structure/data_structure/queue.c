#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

int is_full(Queue* queue) {
    return queue->rear == MAX;
}

int is_empty(Queue* queue) {
    return queue->rear == queue->front;
}

void enqueue(Queue* queue, int item) {
    if (is_full(queue))
        return;
    queue->items[queue->rear++] = item;
}

int dequeue(Queue* queue) {
    if (is_empty(queue))
        return INT_MIN;
    return queue->items[queue->front++];
}

int peek(Queue* queue) {
    if (is_empty(queue))
        return INT_MIN;
    return queue->items[queue->front];
}

int main() {
    Queue* queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    printf("%d dequeued from queue\n", dequeue(queue));  // 출력: 10 dequeued from queue
    printf("Front element is %d\n", peek(queue));        // 출력: Front element is 20
    return 0;
}
