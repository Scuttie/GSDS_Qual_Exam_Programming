class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // 예외 처리: 만약 출발점과 도착점이 동일하다면 경로는 존재하므로 true를 반환
        if (source == destination) return true;

        // 인접 리스트를 이용해 그래프를 표현
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // BFS에 사용할 큐와 방문 여부를 저장할 벡터
        queue<int> q;
        vector<bool> visited(n, false);

        // 초기 상태로 출발점을 큐에 추가하고 방문 표시
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // 현재 정점이 도착점이면 경로가 존재하므로 true 반환
            if (node == destination) return true;

            // 현재 정점과 연결된 모든 인접 정점 탐색
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) { // 방문하지 않은 인접 정점에 대해
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // 탐색 완료 후에도 도착점에 도달하지 못했으면 false 반환
        return false;
    }
};
