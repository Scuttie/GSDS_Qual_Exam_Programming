#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct MaxHeap {
    int size;
    int arr[MAX_SIZE];
} MaxHeap;

// 두 노드를 교환하는 함수
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 힙의 구조를 유지하는 함수
void heapify(MaxHeap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;

    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        heapify(heap, largest);
    }
}

// 힙에 새로운 값을 삽입하는 함수
void insert(MaxHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = value;

    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 최대값을 추출하고 힙을 조정하는 함수
int extractMax(MaxHeap *heap) {
    if (heap->size <= 0)
        return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// 힙을 출력하는 함수
void printHeap(MaxHeap *heap) {
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main() {
    MaxHeap heap;
    heap.size = 0;

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    insert(&heap, 40);

    printHeap(&heap);

    printf("Max value: %d\n", extractMax(&heap));
    printHeap(&heap);

    return 0;
}
