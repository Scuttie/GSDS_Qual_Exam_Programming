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

def bfs(G, key_value):
    
    #bfs면 큐
    
    queue = []
    for temp in G[key_value]:
        queue.append(temp)
    
    visit = []
    
    while len(queue) != 0 :
        # pop    
        cur = queue.pop(0)
        # visist 표시 # 이미 있으면 pass
        if cur not in visit:
            visit.append(cur)
            #해당 노드에 연결된거 queue에 푸시
            for temp in G[cur]:
                queue.append(temp)
        
    #길이가 G랑 같으면 True
    
    if len(G) == len(queue):
        return True
    else:
        return False
    
    # 다르면 False

def find_root_vertices(G):

    # 매 노드 별로 돌아야함 bfs를 통해 해당 노드에서 모든 노드를 갈 수 있는지 체크
    root_possible = []
    import ipdb; ipdb.set_trace()
    for key_value in G:
        print(key_value)
        
        if(bfs(G, key_value)):
            root_possible.append[key_value]
            
    return root_possible

# 테스트 예시
A, B, C = GNode('A'), GNode('B'), GNode('C')
D, E, F = GNode('D'), GNode('E'), GNode('F')
G = dict()
G[A], G[B], G[C] = [C, D], [A, F], [D, B]
G[D], G[E], G[F] = [E], [F], []


print(find_root_vertices(G))  # ['A', 'B', 'C']
