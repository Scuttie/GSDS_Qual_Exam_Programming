from collections import deque

class GNode:
    def __init__(self, id, color='W', p=None):
        self.id = id
        self.color = color
        self.parent = p

    def __str__(self):
        return self.id

    def __hash__(self):
        return hash(self.id)

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    
    while queue:
        node = queue.popleft()
        if node in visited:
            continue
        visited.add(node)
        for neighbor in graph.get(node, []):
            queue.append(neighbor)
    
    return visited

def find_root_vertices(G):
    all_vertices = set(G.keys())
    root_candidates = []
    
    for node in all_vertices:
        reachable = bfs(G, node)
        if reachable == all_vertices:
            root_candidates.append(str(node))
    
    return root_candidates

# 테스트 예시
A, B, C = GNode('A'), GNode('B'), GNode('C')
D, E, F = GNode('D'), GNode('E'), GNode('F')
G = dict()
G[A], G[B], G[C] = [C, D], [A, F], [D, B]
G[D], G[E], G[F] = [E], [F], []

print(find_root_vertices(G))  # ['A', 'B', 'C']
