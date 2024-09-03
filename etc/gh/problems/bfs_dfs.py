from collections import deque

class Graph:
    def __init__(self, n):
        self.adj = [[] for _ in range(n)]
        self.visited = [False] * n

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)  # 무향 그래프의 경우

    def bfs(self, start):
        queue = deque([start])
        self.visited[start] = True

        print("BFS:", end=" ")
        while queue:
            u = queue.popleft()
            print(u, end=" ")

            for v in self.adj[u]:
                if not self.visited[v]:
                    self.visited[v] = True
                    queue.append(v)
        print()

    def dfs(self, u):
        self.visited[u] = True
        print(u, end=" ")

        for v in self.adj[u]:
            if not self.visited[v]:
                self.dfs(v)

    def reset_visited(self):
        self.visited = [False] * len(self.visited)


# 사용 예시
g = Graph(6)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 4)
g.add_edge(3, 4)
g.add_edge(3, 5)
g.add_edge(4, 5)

g.bfs(0)

g.reset_visited()

print("DFS:", end=" ")
g.dfs(0)
print()
