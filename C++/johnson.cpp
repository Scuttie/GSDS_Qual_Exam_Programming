#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

const long long INF = (1LL << 60) - 666;

// 간선 구조체 정의
struct Edge {
    int u, v;
    long long w;
    Edge(int u, int v, long long w) : u(u), v(v), w(w) {}
};

// Bellman-Ford 알고리즘: 음수 가중치 사이클을 감지하기 위해 사용
bool bellman_ford(int n, int start, vector<Edge>& E, vector<long long>& dist) {
    dist[start] = 0;
    for (int i = 0; i < n; i++) {
        for (auto& e : E) {
            if (dist[e.u] == INF) continue;
            if ((dist[e.u] + e.w) < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                if (i == n - 1) return true;  // 음수 가중치 사이클이 존재함
            }
        }
    }
    return false;
}

// Dijkstra 알고리즘: 단일 시작점 최단 경로를 계산하기 위해 사용
vector<long long> dijkstra(int n, int start, vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (dist[current] < distance) {
            continue;
        }

        for (int i = 0; i < adj[current].size(); i++) {
            int next = adj[current][i].first;
            int nextDistance = distance + adj[current][i].second;

            if (nextDistance < dist[next]) {
                dist[next] = nextDistance;
                pq.push(make_pair(nextDistance, next));
            }
        }
    }
    return dist;
}

// Johnson's Algorithm: 모든 쌍 최단 경로를 계산
void johnson(int n, vector<Edge> edges) {
    // Step 1: 새로운 노드 s를 추가하고 s에서 모든 노드로 가는 가중치 0의 간선 추가
    vector<Edge> newEdges;
    for (const auto& edge : edges) {
        newEdges.push_back(Edge(edge.u - 1, edge.v - 1, edge.w)); // 인덱스를 0 기반으로 조정
    }
    for (int i = 0; i < n; i++) {
        newEdges.push_back(Edge(n, i, 0)); // 새로운 노드 s 추가
    }

    // Step 2: Bellman-Ford 알고리즘으로 h(v) 계산
    vector<long long> h(n + 1, INF);
    if (bellman_ford(n + 1, n, newEdges, h)) {
        cout << "Negative cycle detected" << endl;
        return;
    }

    // Step 3: 간선의 가중치를 h(v)를 이용해 재조정
    vector<vector<pair<int, int>>> adj(n);
    for (const auto& edge : edges) {
        int newWeight = edge.w + h[edge.u - 1] - h[edge.v - 1]; // 가중치 조정
        adj[edge.u - 1].push_back({edge.v - 1, newWeight});
    }

    // Step 4: 각 정점에 대해 Dijkstra 알고리즘 실행
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for (int u = 0; u < n; u++) {
        dist[u] = dijkstra(n, u, adj);
    }

    // Step 5: 최종 최단 경로 계산 및 출력
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (dist[u][v] != INF) {
                dist[u][v] = dist[u][v] - h[u] + h[v];
            }
        }
    }

    // 최단 거리 행렬 출력
    cout << "Shortest distance matrix:" << endl;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (dist[u][v] == INF)
                cout << "INF ";
            else
                cout << dist[u][v] << " ";
        }
        cout << "\n";
    }
}

int main() {
    // 노드의 개수와 간선 정의
    int n = 3;
    vector<Edge> edges;

    // 간선 추가
    edges.push_back(Edge(1, 2, 2));
    edges.push_back(Edge(2, 3, -15));
    edges.push_back(Edge(1, 3, -10));

    // Johnson's 알고리즘 실행
    johnson(n, edges);

    return 0;
}
