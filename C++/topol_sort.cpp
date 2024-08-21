#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> seen, order;

void dfs(int here) {
    seen[here] = 1;
    for (int there = 0; there < adj[here].size(); ++there) {
        if (adj[here][there] && !seen[there]) {
            dfs(there);
        }
    }
    order.push_back(here); // 나중에 reverse해서, 시작점부터 출력될 예정!
}

// adj에 주어진 그래프를 위상 정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면 빈 벡터를 반환한다.
vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();

    // 모든 정점에 대해 DFS 시행
    for (int i = 0; i < adj.size(); ++i) {
        if (!seen[i]) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());

    // 역방향 간선이 존재하는지 확인하여 DAG 여부 판단
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (adj[order[j]][order[i]]) {
                return vector<int>(); // DAG가 아닌 경우 빈 벡터 반환
            }
        }
    }
    return order; // DAG인 경우 위상 정렬 결과 반환
}

int main() {
    // 노드의 개수
    int n = 6;
    adj = vector<vector<int>>(n, vector<int>(n, 0));

    // 간선 추가 (Directed Acyclic Graph)
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    // 위상 정렬 수행
    vector<int> result = topologicalSort();

    // 결과 출력
    if (result.empty()) {
        cout << "The graph is not a Directed Acyclic Graph (DAG)." << endl;
    } else {
        cout << "Topological Sort: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
