#ifndef QE_PROB2_H
#define QE_PROB2_H

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;  // MRU(가장 최근 사용) 노드
    Node* tail;  // LRU(가장 오래된) 노드
} LRUCache;

Node* createNode(int key, int value);
LRUCache* lRUCacheCreate(int capacity);
void lRUCacheFree(LRUCache* cache);
Node* lRUCacheMRU(LRUCache* cache);
Node* lRUCacheLRU(LRUCache* cache);
int lRUCacheGet(LRUCache* cache, int key);
void lRUCachePut(LRUCache* cache, int key, int value);
void lRUCacheDisplay(LRUCache* cache);

#endif
