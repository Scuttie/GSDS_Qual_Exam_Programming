#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

# define MAX_V 10000

// 전역 변수 초기화
vector<pair<int, int>> adj[MAX_V]; // 인접 리스트
vector<bool> inMST(MAX_V, false);  // MST에 포함되었는지를 표시하는 배열

int prim(int n) {
    // 우선순위 큐 (최소 힙) 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mst_weight = 0; // MST의 총 가중치
    pq.push(make_pair(0, 0));    // {weight, node} 형식으로 시작 노드를 큐에 추가

    while (!pq.empty()) {
        // 가장 작은 가중치를 가진 노드를 꺼내고
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 이미 MST에 포함된 노드라면 스킵
        if (inMST[u]) continue;

        // 해당 노드를 MST에 추가
        mst_weight += weight;
        inMST[u] = true;

        // 해당 노드와 연결된 다른 노드를 확인하여 큐에 추가
        for (vector<pair<int, int>>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = it->first;
            int w = it->second;
            if (!inMST[v]) {
                pq.push(make_pair(w, v));
            }
        }
    }
    return mst_weight;
}

int main() {
    int n = 4; // number of vertices

    // 그래프 정의 (무방향 그래프이므로 양방향으로 간선 추가)
    adj[0].push_back(make_pair(1, 10));
    adj[0].push_back(make_pair(2, 6));
    adj[0].push_back(make_pair(3, 5));
    adj[1].push_back(make_pair(0, 10));
    adj[1].push_back(make_pair(3, 15));
    adj[2].push_back(make_pair(0, 6));
    adj[2].push_back(make_pair(3, 4));
    adj[3].push_back(make_pair(0, 5));
    adj[3].push_back(make_pair(1, 15));
    adj[3].push_back(make_pair(2, 4));

    cout << "Weight of MST is " << prim(n) << endl;

    return 0;
}
