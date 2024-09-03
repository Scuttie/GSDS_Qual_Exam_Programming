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
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]: 
                if neighbor not in visited:
                    queue.append(neighbor)
    return visited

def find_root_vertices(G):
    all_vertices = set(G.keys())
    root_vertices = []

    for vertex in all_vertices:
        reachable = bfs(G,vertex)
        if reachable == all_vertices:
            root_vertices.append(vertex.id)
    print(sorted(root_vertices))


if __name__ == '__main__': 
    A, B, C = GNode('A'), GNode('B'), GNode('C')
    D, E, F = GNode('D'), GNode('E'), GNode('F')

    G = {
        A: [C,D],
        B: [A,F],
        C: [D,B],
        D: [E],
        E: [F],
        F: []
    }

    find_root_vertices(G)