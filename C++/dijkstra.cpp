#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_V 100
#define INF 1000 // ; 붙이면 안됨.

int v, e; 
vector<pair<int, int>> adj[MAX_V];
vector<int> parent(MAX_V, INF); // predecessor 값을 담는다.
vector<int> dist(MAX_V, INF); // 거리

void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
                parent[there] = here;
            }
        }
    }
}

vector<int> shortestPath(int v, const vector<int>& parent) {
    vector<int> path(1, v);
    while (v != parent[v]) {
        v = parent[v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // 노드의 개수와 간선의 개수 설정
    v = 4; // 노드의 개수
    e = 5; // 간선의 개수

    // 시작 노드 설정
    int start_node = 0;

    // 부모노드 초기화: 자기자신으로 가도록 초기화하기
    for (int i = 0; i < v + 1; ++i) {
        parent[i] = i;
    }

    // 간선 저장
    adj[0].push_back(make_pair(1, 10));
    adj[0].push_back(make_pair(2, 20));
    adj[0].push_back(make_pair(3, 30));
    adj[1].push_back(make_pair(0, 10));
    adj[1].push_back(make_pair(2, 5));
    adj[1].push_back(make_pair(4, 50));
    adj[2].push_back(make_pair(0, 20));
    adj[2].push_back(make_pair(1, 5));
    adj[2].push_back(make_pair(3, 15));
    adj[2].push_back(make_pair(4, 10));
    adj[3].push_back(make_pair(0, 30));
    adj[3].push_back(make_pair(2, 15));
    adj[3].push_back(make_pair(4, 5));
    adj[4].push_back(make_pair(1, 50));
    adj[4].push_back(make_pair(2, 10));
    adj[4].push_back(make_pair(3, 5));

    // 다익스트라 함수 실행
    dijkstra(start_node);

    // 최소 비용 배열 출력
    for (int i = 0; i < v; ++i) {
        if (dist[i] == INF) {
            cout << "INF" << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    // 각 노드들의 shortest path 출력
    for (int i = 0; i < v; ++i) {
        vector<int> shortestpath = shortestPath(i, parent);
        cout << i << "'s shortest path: ";
        for (int j = 0; j < shortestpath.size(); ++j) {
            cout << shortestpath[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
