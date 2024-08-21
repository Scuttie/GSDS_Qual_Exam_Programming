#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 10000000; // 무한대 값 정의

void floydWarshall(int n, vector<vector<int>>& distance, vector<vector<int>>& predecessor) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 경유 노드를 통해 더 짧은 경로가 있는지 확인
                if (distance[i][k] != INF && distance[k][j] != INF && distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    predecessor[i][j] = predecessor[k][j]; // 경유 노드 k를 거치므로 k의 부모 노드를 저장
                }
            }
        }
    }
}

int main() {
    int n = 4; // 노드의 개수
    vector<vector<int>> distance = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    vector<vector<int>> predecessor(n, vector<int>(n));

    // 초기화: 자기 자신으로 가는 경로의 부모는 자기 자신으로 설정
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && distance[i][j] != INF) {
                predecessor[i][j] = i;
            } else {
                predecessor[i][j] = -1; // 경로가 없는 경우
            }
        }
    }

    // Floyd-Warshall 알고리즘 실행
    floydWarshall(n, distance, predecessor);

    // 최단 거리 행렬 출력
    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[i][j] == INF) {
                cout << "INF" << " ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }

    // 경로 행렬 출력
    cout << "Predecessor matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (predecessor[i][j] == -1) {
                cout << "NIL" << " ";
            } else {
                cout << predecessor[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
