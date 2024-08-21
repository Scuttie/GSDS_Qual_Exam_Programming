#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

const int INF = 10000000;  // 무한대를 나타내는 큰 수
int nodenum = 6;  // 노드의 개수

// Bellman-Ford 알고리즘 함수
bool bellman(int start, int vertexes, int edges, vector<tuple<int, int, int>>& graph, vector<int>& distance, vector<int>& predecessor) {
    distance[start] = 0;  // 시작 노드의 거리는 0으로 설정

    // 모든 간선에 대해 V-1번 반복
    for (int i = 1; i <= vertexes; ++i) {
        for (int j = 0; j < edges; ++j) {
            int u, v, weight;
            tie(u, v, weight) = graph[j];  // 간선 정보 (시작, 끝, 가중치) 추출

            // Relaxation 단계: 거리가 줄어들 수 있으면 갱신
            if (distance[u] != INF && distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                predecessor[v] = u;  // 경로 추적을 위한 이전 노드 저장

                // V번째 반복에서 거리 갱신이 일어나면 음수 사이클 존재
                if (i == vertexes) {
                    return true;  // 음수 사이클 존재
                }
            }
        }
    }

    return false;  // 음수 사이클이 없음
}

int main() {
    // 그래프 초기화 (시작 노드, 끝 노드, 가중치)
    vector<tuple<int, int, int>> graph = {
        {1, 2, 4},
        {1, 3, 2},
        {2, 3, 3},
        {2, 4, 2},
        {3, 2, 1},
        {3, 5, 5},
        {4, 5, 1},
        {4, 6, 4},
        {5, 6, 2}
    };

    vector<int> distance(nodenum + 1, INF);  // 각 노드까지의 거리를 무한대로 초기화
    vector<int> predecessor(nodenum + 1, -1);  // 경로 추적을 위한 이전 노드 초기화

    int start_node = 1;  // 시작 노드 설정

    // Bellman-Ford 알고리즘 실행
    bool has_negative_cycle = bellman(start_node, nodenum, graph.size(), graph, distance, predecessor);

    if (has_negative_cycle) {
        cout << "Graph contains a negative-weight cycle." << endl;
    } else {
        cout << "Shortest distances from node " << start_node << ":" << endl;
        for (int i = 1; i <= nodenum; ++i) {
            if (distance[i] == INF) {
                cout << "Node " << i << ": INF" << endl;
            } else {
                cout << "Node " << i << ": " << distance[i] << endl;
            }
        }
    }

    return 0;
}
