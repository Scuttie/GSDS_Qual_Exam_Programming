#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선을 나타내는 구조체
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 특정 정점의 부모를 찾는 함수 (find 연산)
int findParent(vector<int>& parent, int u) {
    if (parent[u] != u) {
        parent[u] = findParent(parent, parent[u]);
    }
    return parent[u];
}

// 두 정점을 연결하는 함수 (union 연산)
void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Kruskal 알고리즘 구현
int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // 간선을 가중치 순으로 정렬

    vector<int> parent(n);
    vector<int> rank(n, 0);

    // 초기화: 모든 정점이 자기 자신을 부모로 가짐
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    int mst_weight = 0;
    vector<Edge> mst_edges;

    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        // find 연산을 통해 사이클 여부를 확인
        if (findParent(parent, u) != findParent(parent, v)) {
            mst_weight += weight;
            mst_edges.push_back(edge);
            unionSets(parent, rank, u, v);
        }
    }

    // 선택된 간선들 출력 (MST의 구성 간선들)
    cout << "Edges in the MST:\n";
    for (const Edge& edge : mst_edges) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }

    return mst_weight;
}

int main() {
    int n = 4; // number of vertices
    vector<Edge> edges;

    // 간선 정의
    edges.push_back({0, 1, 10});
    edges.push_back({0, 2, 6});
    edges.push_back({0, 3, 5});
    edges.push_back({1, 3, 15});
    edges.push_back({2, 3, 4});

    kruskal(n, edges);

    return 0;
}
