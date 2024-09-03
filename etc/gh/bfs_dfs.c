#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// 그래프 구조체 정의
typedef struct Graph {
    int adj[MAX][MAX];
    int visited[MAX];
    int n; // 노드의 개수
} Graph;

// 그래프 초기화
void initGraph(Graph* g, int n) {
    g->n = n;
    for (int i = 0; i < n; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// 간선 추가
void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1; // 무향 그래프의 경우
}

// BFS 구현
void bfs(Graph* g, int start) {
    int queue[MAX], front = 0, rear = 0;

    printf("BFS: ");
    g->visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < g->n; v++) {
            if (g->adj[u][v] && !g->visited[v]) {
                g->visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

// DFS 구현 (재귀)
void dfs(Graph* g, int u) {
    g->visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < g->n; v++) {
        if (g->adj[u][v] && !g->visited[v]) {
            dfs(g, v);
        }
    }
}

int main() {
    Graph g;
    initGraph(&g, 6);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 5);
    addEdge(&g, 4, 5);

    bfs(&g, 0);

    // DFS 시작 전 방문 배열 초기화
    for (int i = 0; i < g.n; i++) {
        g.visited[i] = 0;
    }

    printf("DFS: ");
    dfs(&g, 0);
    printf("\n");

    return 0;
}
