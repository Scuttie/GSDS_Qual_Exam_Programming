class GNode:
    def __init__(self, id):
        self.id = id   # 문자열(예: 'a', 'b', 'c' 등)

    def __str__(self):
        return self.id  # print 시 보이도록

def paths(G: dict[GNode, list[GNode]], s: GNode, t: GNode) -> list[list[str]]:
    """
    G: 방향 그래프(acyclic) - { GNode -> list of GNode }
    s, t: 시작점, 도착점
    반환: s 에서 t 로 가는 모든 경로를 2차원 리스트로 (각 경로는 [노드id, 노드id, ...])
    """
    all_paths = []  # 모든 경로를 저장할 리스트
    
    def dfs(current: GNode, path: list[GNode]):
        # current == t 이면 하나의 경로가 완성
        if current == t:
            # GNode.id 로만 구성된 리스트를 만들어 결과에 저장
            all_paths.append([node.id for node in path])
            return
        
        # 아직 도착점이 아니라면 다음 이웃(간선)들로 확장
        for nxt in G.get(current, []):
            path.append(nxt)        # 경로에 다음 노드 추가
            dfs(nxt, path)          # 재귀 호출
            path.pop()              # 백트래킹 (원상복구)
    
    # 시작 노드 s 부터 DFS를 진행
    dfs(s, [s])
    return all_paths

if __name__ == "__main__":
    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a] = [b, c]    # a -> b, c
    G[b] = [d]       # b -> d
    G[c] = [b, d]    # c -> b, d
    G[d] = []        # d -> (없음)

    # a 에서 c 로 가는 모든 경로 찾기
    result = paths(G, a, c)
    print(result)  
    # 예: [["a", "c"], ["a", "b", "d", "c"]]  (순서는 달라도 무방)
