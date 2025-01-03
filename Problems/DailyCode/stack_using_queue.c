#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 큐의 최대 용량 정의
#define QUEUE_CAPACITY 100

// 큐 구조체 정의
typedef struct {
    int data[QUEUE_CAPACITY]; // 큐의 데이터 배열
    int front;                // 큐의 앞쪽 인덱스
    int rear;                 // 큐의 뒤쪽 인덱스
    int size;                 // 현재 큐의 크기
} Queue;

// 큐 초기화 함수
Queue* queueCreate() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;

    q->front = 0;
    q->rear = 0;
    q->size = 0;
    memset(q->data, 0, sizeof(q->data));

    return q;
}

// 큐에 요소를 추가하는 함수 (Enqueue)
bool enqueue(Queue* q, int x) {
    if (q->size >= QUEUE_CAPACITY) {
        // 큐가 가득 찼을 경우
        return false;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % QUEUE_CAPACITY;
    q->size++;
    return true;
}

// 큐에서 요소를 제거하고 반환하는 함수 (Dequeue)
int dequeue(Queue* q) {
    if (q->size == 0) {
        // 큐가 비어있을 경우
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_CAPACITY;
    q->size--;
    return val;
}

// 큐의 앞 요소를 반환하는 함수 (Peek)
int queuePeek(Queue* q) {
    if (q->size == 0) {
        // 큐가 비어있을 경우
        return -1;
    }
    return q->data[q->front];
}

// 큐가 비어있는지 확인하는 함수
bool queueEmpty(Queue* q) {
    return q->size == 0;
}

// 큐 메모리를 해제하는 함수
void queueFree(Queue* q) {
    if (q) {
        free(q);
    }
}

// MyStack 구조체 정의: 두 개의 큐를 사용하여 LIFO 스택 구현
typedef struct {
    Queue* q1; // 첫 번째 큐
    Queue* q2; // 두 번째 큐
} MyStack;

/**
 * 스택을 생성하고 초기화하는 함수
 * 
 * @return 초기화된 MyStack 포인터
 */
MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    if (!obj) return NULL;

    obj->q1 = queueCreate(); // 첫 번째 큐 생성
    obj->q2 = queueCreate(); // 두 번째 큐 생성

    if (!obj->q1 || !obj->q2) {
        // 큐 생성에 실패하면 할당된 메모리 해제
        if (obj->q1) queueFree(obj->q1);
        if (obj->q2) queueFree(obj->q2);
        free(obj);
        return NULL;
    }

    return obj;
}

/**
 * 스택에 요소를 추가하는 함수
 * 
 * @param obj 스택 객체
 * @param x 추가할 정수 값
 */
void myStackPush(MyStack* obj, int x) {
    if (obj && obj->q1) {
        enqueue(obj->q1, x); // 첫 번째 큐에 요소 추가
    }
}

/**
 * 스택에서 요소를 제거하고 반환하는 함수
 * 
 * @param obj 스택 객체
 * @return 제거된 정수 값
 */
int myStackPop(MyStack* obj) {
    if (obj && obj->q1 && obj->q2) {
        // 첫 번째 큐가 비어있으면 스택도 비어있음
        if (queueEmpty(obj->q1)) {
            return -1;
        }

        // 첫 번째 큐의 모든 요소를 두 번째 큐로 이동, 마지막 요소는 제거
        while (obj->q1->size > 1) {
            int val = dequeue(obj->q1);
            enqueue(obj->q2, val);
        }

        // 마지막 요소를 제거 (Pop)
        int topVal = dequeue(obj->q1);

        // 큐를 교환
        Queue* temp = obj->q1;
        obj->q1 = obj->q2;
        obj->q2 = temp;

        return topVal;
    }
    return -1; // 스택이 비어있을 경우
}

/**
 * 스택의 앞 요소를 반환하는 함수
 * 
 * @param obj 스택 객체
 * @return 스택의 앞에 있는 정수 값
 */
int myStackTop(MyStack* obj) {
    if (obj && obj->q1 && obj->q2) {
        if (queueEmpty(obj->q1)) {
            return -1;
        }

        // 첫 번째 큐의 모든 요소를 두 번째 큐로 이동, 마지막 요소는 반환
        while (obj->q1->size > 1) {
            int val = dequeue(obj->q1);
            enqueue(obj->q2, val);
        }

        // 마지막 요소를 가져옴 (Top)
        int topVal = dequeue(obj->q1);
        enqueue(obj->q2, topVal); // 다시 두 번째 큐에 추가

        // 큐를 교환
        Queue* temp = obj->q1;
        obj->q1 = obj->q2;
        obj->q2 = temp;

        return topVal;
    }
    return -1; // 스택이 비어있을 경우
}

/**
 * 스택이 비어있는지 확인하는 함수
 * 
 * @param obj 스택 객체
 * @return 스택이 비어있으면 true, 아니면 false
 */
bool myStackEmpty(MyStack* obj) {
    if (obj) {
        return queueEmpty(obj->q1) && queueEmpty(obj->q2); // 두 큐가 모두 비어있어야 스택도 비어있음
    }
    return true; // 스택 객체가 NULL인 경우 비어있다고 간주
}

/**
 * 스택의 메모리를 해제하는 함수
 * 
 * @param obj 스택 객체
 */
void myStackFree(MyStack* obj) {
    if (obj) {
        if (obj->q1) queueFree(obj->q1); // 첫 번째 큐 메모리 해제
        if (obj->q2) queueFree(obj->q2); // 두 번째 큐 메모리 해제
        free(obj); // 스택 구조체 메모리 해제
    }
}

/**
 * MyStack 구조체가 다음과 같이 호출될 것임:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */

// 테스트를 위한 메인 함수 (선택 사항)
int main() {
    MyStack* obj = myStackCreate();
    if (!obj) {
        printf("스택 생성 실패\n");
        return -1;
    }

    // 예제 1
    myStackPush(obj, 1);
    myStackPush(obj, 2);
    printf("Top: %d\n", myStackTop(obj)); // 출력: 2
    printf("Pop: %d\n", myStackPop(obj)); // 출력: 2
    printf("Empty: %s\n", myStackEmpty(obj) ? "true" : "false"); // 출력: false

    // 추가 테스트
    myStackPush(obj, 3);
    printf("Top: %d\n", myStackTop(obj)); // 출력: 3
    printf("Pop: %d\n", myStackPop(obj)); // 출력: 3
    printf("Pop: %d\n", myStackPop(obj)); // 출력: 1
    printf("Empty: %s\n", myStackEmpty(obj) ? "true" : "false"); // 출력: true

    myStackFree(obj); // 스택 메모리 해제
    return 0;
}
