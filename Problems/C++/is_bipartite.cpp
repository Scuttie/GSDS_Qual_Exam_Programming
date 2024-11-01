class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1: 미방문, 0: 첫 번째 색, 1: 두 번째 색

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {  // 아직 색칠되지 않은 노드에 대해 BFS 수행
                queue<int> q;
                q.push(i);
                color[i] = 0;  // 시작 노드에 첫 번째 색 할당

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {  // 인접 노드가 아직 색칠되지 않은 경우
                            color[neighbor] = 1 - color[node];  // 현재 노드와 다른 색으로 색칠
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            // 인접한 노드가 같은 색이라면 이분 그래프가 아님
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
