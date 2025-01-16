from collections import deque

class GNode:
    def __init__(self, id, color='W', p=None):
        self.id = id
        self.color = color
        self.parent = p
    
    def __str__(self):
        return self.id
    
    def __hash__(self):
        # 사전(dict)에서 key로 사용하기 위해 hash 정의
        return hash(self.id)
    
    def __eq__(self, other):
        # id가 같으면 같은 노드로 취급
        if not isinstance(other, GNode):
            return False
        return self.id == other.id

def bfs(start: GNode, G: dict[GNode, list[GNode]]) -> set[GNode]:
    """ 
    start 노드에서 시작하여, 
    간선 방향을 따라 도달 가능한 모든 노드를 방문한 뒤,
    방문 집합을 반환한다.
    """
    visited = set()
    queue = deque([start])
    visited.add(start)
    
    while queue:
        current = queue.popleft()
        # current에서 갈 수 있는 모든 방향 확인
        for nxt in G.get(current, []):
            if nxt not in visited:
                visited.add(nxt)
                queue.append(nxt)
    return visited

def find_root_vertices(G: dict[GNode, list[GNode]]) -> list[str]:
    """
    Directed Graph G에서, 모든 다른 노드에 도달할 수 있는 노드(들)의 id를
    string list 형태로 반환한다.
    """
    # 그래프에 존재하는 모든 노드 집합
    all_nodes = set(G.keys())  # G의 key로 등록된 노드들

    root_vertices = []
    for node in all_nodes:
        visited = bfs(node, G)
        # 모든 노드에 도달 가능하면 root vertex
        if visited == all_nodes:
            root_vertices.append(node.id)
    
    return root_vertices

# ------------------------------------------------------------------------------
# 아래는 문제에 제시된 예시 테스트 코드
# ------------------------------------------------------------------------------

if __name__ == "__main__":
    A, B, C = GNode('A'), GNode('B'), GNode('C')
    D, E, F = GNode('D'), GNode('E'), GNode('F')

    G = dict()
    G[A] = [C, D]
    G[B] = [A, F]
    G[C] = [D, B]
    G[D] = [E]
    G[E] = [F]
    G[F] = []

    result = find_root_vertices(G)
    print(result)   # ['A', 'B', 'C'] 기대
