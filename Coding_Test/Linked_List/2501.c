#include <stdio.h>
#include <stdlib.h>
#include "2501.h"

// ---------- [ 헬퍼 함수 선언 ] ----------
static void removeNode(LRUCache* cache, Node* node);
static void addNodeToHead(LRUCache* cache, Node* node);
static void moveToHead(LRUCache* cache, Node* node);

// 노드 생성 함수
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 캐시 생성 함수
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL; // 초기에는 비어 있음
    cache->tail = NULL; // 초기에는 비어 있음
    return cache;
}

// 캐시 메모리 해제 함수
void lRUCacheFree(LRUCache* cache) {
    Node* cur = cache->head;
    while(cur) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(cache);
}

// MRU(가장 최근에 사용한 노드) 반환
Node* lRUCacheMRU(LRUCache* cache) {
    return cache->head;
}

// LRU(가장 오래된 노드) 반환
Node* lRUCacheLRU(LRUCache* cache) {
    return cache->tail;
}

// 캐시에서 key에 해당하는 value 반환 (없으면 -1)
// 조회된 노드를 MRU로 갱신
int lRUCacheGet(LRUCache* cache, int key) {
    Node* cur = cache->head;
    // 단순 연결 리스트 선형 검색
    while(cur) {
        if(cur->key == key) {
            // 사용됐으므로 MRU(헤드)로 이동
            moveToHead(cache, cur);
            return cur->value;
        }
        cur = cur->next;
    }
    // 못 찾았을 시 -1 반환
    return -1;
}

// 캐시에 (key, value) 삽입/갱신
void lRUCachePut(LRUCache* cache, int key, int value) {
    Node* cur = cache->head;
    // 이미 존재하는 키인지 확인
    while(cur) {
        if(cur->key == key) {
            // 존재하면 값 갱신 후 MRU로 이동
            cur->value = value;
            moveToHead(cache, cur);
            return;
        }
        cur = cur->next;
    }
    
    // 기존에 없는 키라면 새 노드 생성
    Node* newNode = createNode(key, value);

    // 캐시가 가득 찼다면 LRU(꼬리) 노드 제거
    if (cache->size == cache->capacity) {
        removeNode(cache, cache->tail);
        cache->size--;
    }

    // 새 노드를 MRU 위치(헤드)에 삽입
    addNodeToHead(cache, newNode);
    cache->size++;
}

// 캐시 내용을 MRU -> LRU 순서로 출력
void lRUCacheDisplay(LRUCache* cache) {
    printf("Cache (MRU -> LRU): ");
    Node* cur = cache->head;
    while(cur) {
        printf("[%d:%d] ", cur->key, cur->value);
        cur = cur->next;
    }
    printf("\n");
}

// ---------- [ 이중 연결 리스트 헬퍼 함수 정의 ] ----------

// 이중 연결 리스트에서 특정 노드를 제거
static void removeNode(LRUCache* cache, Node* node) {
    if (!node) return;

    if (node->prev) { 
        node->prev->next = node->next; 
    } else {
        // node가 head라면 head 갱신
        cache->head = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        // node가 tail이라면 tail 갱신
        cache->tail = node->prev;
    }
    node->prev = NULL;
    node->next = NULL;
}

// 새 노드를 MRU(헤드) 위치에 추가
static void addNodeToHead(LRUCache* cache, Node* node) {
    node->prev = NULL;
    node->next = cache->head;

    if (cache->head) {
        cache->head->prev = node;
    }
    cache->head = node;

    // 캐시가 비어 있었다면 tail도 동일 노드
    if (!cache->tail) {
        cache->tail = node;
    }
}

// 특정 노드를 리스트에서 분리 후 MRU(헤드)로 이동
static void moveToHead(LRUCache* cache, Node* node) {
    removeNode(cache, node);
    addNodeToHead(cache, node);
}

// ---------- [ 테스트 메인 함수 ] ----------
int main() {
    LRUCache* cache = lRUCacheCreate(3);
    lRUCachePut(cache, 1, 1);
    lRUCacheDisplay(cache); // MRU->LRU: [1:1]
    
    lRUCachePut(cache, 2, 2);
    lRUCacheDisplay(cache); // [2:2] [1:1]
    
    lRUCachePut(cache, 3, 3);
    lRUCacheDisplay(cache); // [3:3] [2:2] [1:1]
    
    int value = lRUCacheGet(cache, 2);  
    printf("lRUCacheGet(cache, 2) => %d\n", value);
    lRUCacheDisplay(cache); // [2:2] [3:3] [1:1]
    
    lRUCachePut(cache, 5, 8);
    lRUCacheDisplay(cache); // [5:8] [2:2] [3:3] (1:1이 LRU로 제거됨)
    
    lRUCachePut(cache, 4, 4);
    lRUCacheDisplay(cache); // [4:4] [5:8] [2:2] (3:3이 LRU로 제거됨)

    // 리소스 해제
    lRUCacheFree(cache);
    return 0;
}
