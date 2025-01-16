# GNode definition
class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id      # 노드 식별자 (문자열)
        self.color = color  # 방문 색깔 (W, G, B)
        self.distance = d    # s로부터의 거리(레벨)
        self.parent = p      # 부모 노드
        # 필요하다면 멤버 추가 가능

    def __str__(self):
        return self.id


def bfs(G, s):
    """
    (a) [10 pts] 너비 우선 탐색 (BFS) 알고리즘.
    G : undirected graph (dictionary 형태)
        key   = GNode
        value = 해당 GNode와 인접한 GNode들의 리스트
    s : 시작점 GNode
    
    모든 노드에 대해
    - color = 'W' (white)
    - distance = 무한대(또는 큰 값)
    - parent = None
    으로 초기화한 뒤 BFS를 수행하며 값을 갱신한다.
    """
    # 모든 노드 초기화
    for node in G.keys():
        node.color = 'W'
        node.distance = float('inf')
        node.parent = None

    # 시작 노드 초기화
    s.color = 'G'         # Gray
    s.distance = 0
    s.parent = None

    # 큐 초기화
    from collections import deque
    queue = deque([s])

    # BFS 수행
    while queue:
        u = queue.popleft()
        for v in G[u]:
            if v.color == 'W':
                v.color = 'G'
                v.distance = u.distance + 1
                v.parent = u
                queue.append(v)
        # 탐색 완료된 노드는 검정(Black)으로 표시
        u.color = 'B'


def level_partition(G, s):
    """
    (b) [40 pts] BFS를 사용하여 레벨 파티션을 구하는 함수.
    - 먼저 bfs(G, s)를 통해 각 노드의 distance(레벨)를 계산
    - distance가 같은 노드들끼리 묶어서 리턴한다.
    
    리턴값 예시:
    [[s], [r, w], [v, t, x], [u, y]]
    처럼 distance(=level)가 0, 1, 2, 3 ... 순으로 묶인다.
    """
    # 먼저 BFS 수행
    bfs(G, s)

    # distance 값에 따라 노드를 그룹핑하기 위해
    # distance의 최댓값 찾기
    max_distance = max(node.distance for node in G.keys())

    # 레벨(=distance) 별로 노드를 담을 리스트
    # 0부터 max_distance까지 각 distance에 대한 리스트를 만든다.
    partitions = [[] for _ in range(max_distance + 1)]

    # 모든 노드를 순회하며 distance에 맞는 파티션에 넣는다
    for node in G.keys():
        partitions[node.distance].append(node)

    # 각 레벨별로 노드 id (또는 노드 객체)만 보이도록 할 수도 있고,
    # 문제 예시는 [[s], [r, w], ...] 형태로 문자열로 보이므로
    # 출력 형식을 맞추려면 아래처럼 처리 가능
    # 만약 제출 시에는 print를 사용하지 말라고 했으니,
    # 단지 return 시 형식을 맞춰주면 됩니다.

    # 노드 id 문자열만으로 구성된 2차원 리스트를 만들고 싶으면:
    # result = []
    # for level_list in partitions:
    #     result.append([str(node) for node in level_list])
    #
    # return result

    # 문제에서 "returns '[[s], [r, w], [v, t, x], [u, y]]'" 라고 예시가 있으므로,
    # 문자열이 아닌, 실제 GNode 리스트를 반환해도 무방합니다.
    # 여기서는 GNode 객체 그대로 돌려주겠습니다.

    return partitions
