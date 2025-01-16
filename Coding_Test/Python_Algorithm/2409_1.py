class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        # 문제 본문에서 사용한 필드들 (필요시 활용)
        self.height = 0
        self.parent = None

def height(T: TNode) -> int:
    """
    트리의 높이를 재귀적으로 구한다.
    (루트 ~ 리프 간 가장 긴 경로상의 '간선' 개수)
    """
    # 공백 트리이면 -1을 리턴하면
    # 리프 노드 높이를 0으로 정의할 수 있다.
    # 만약 리프 노드 높이를 1로 보고 싶다면,
    # base case를 0으로 두고 밑에서 +1 하는 방식을 조정하면 됨.
    if T is None:
        return -1
    return 1 + max(height(T.left), height(T.right))

def is_balanced(T: TNode) -> bool:
    """
    모든 노드에 대해 왼쪽·오른쪽 서브트리 높이차가 1 이하인지 검사.
    """
    def check(node: TNode) -> int:
        # 밑에서 높이를 반환하되, 만약 -1이 반환되면
        # 서브트리에서 이미 밸런스가 깨졌다는 의미로 사용.
        if node is None:
            return 0
        left_h = check(node.left)
        if left_h == -1:
            return -1
        right_h = check(node.right)
        if right_h == -1:
            return -1
        
        # 높이차가 1 넘으면 -1(불균형) 리턴
        if abs(left_h - right_h) > 1:
            return -1
        
        # 서브트리가 균형 잡혀 있다면, 그 서브트리의 높이 리턴
        return max(left_h, right_h) + 1

    # check 함수가 -1을 리턴하면 불균형
    return (check(T) != -1)

def is_bst(T: TNode) -> bool:
    """
    (low, high) 범위를 넘겨가며 재귀적으로 검사.
    """
    def check(node: TNode, low: float, high: float) -> bool:
        if node is None:
            return True
        if not (low < node.val < high):
            return False
        return (check(node.left,  low,        node.val) and
                check(node.right, node.val,   high))
    
    return check(T, float('-inf'), float('inf'))

def common_ancestors(T: TNode, U: TNode, V: TNode) -> list[int]:
    """
    DFS 순서대로 T에서 U, V의 공통 조상을 모두 찾는다.
    """
    def is_ancestor(root: TNode, target: TNode) -> bool:
        if not root:
            return False
        if root == target:
            return True
        return is_ancestor(root.left, target) or is_ancestor(root.right, target)

    result = []
    
    def dfs(node: TNode):
        if node is None:
            return
        # node가 U, V의 공통 조상인지 판별
        if is_ancestor(node, U) and is_ancestor(node, V):
            result.append(node.val)
        dfs(node.left)
        dfs(node.right)
    
    dfs(T)
    return result

def lca(T: TNode, U: TNode, V: TNode) -> int:
    """
    T에서 U, V의 LCA(Lowest Common Ancestor)를 찾는다.
    없으면 -1
    """
    def find_lca(node: TNode, p: TNode, q: TNode) -> TNode:
        if node is None:
            return None
        # 만약 현재 노드가 p, q 중 하나이면 리턴
        if node == p or node == q:
            return node
        
        left = find_lca(node.left, p, q)
        right = find_lca(node.right, p, q)

        # 왼쪽과 오른쪽에서 각각 발견되었다면 현재 노드가 LCA
        if left and right:
            return node
        # 어느 한 쪽만 발견되었으면 그 쪽이 LCA
        return left if left else right
    
    ans = find_lca(T, U, V)
    return ans.val if ans else -1


# ---------------------------------------------------------------------------------
# 아래는 문제에서 주어진 테스트 코드와 동일하게 동작하는지 확인 예시입니다.
# 직접 실행해 보려면 파이썬 환경에서 돌려보세요.
# ---------------------------------------------------------------------------------

if __name__ == "__main__":
    T7, T8, T9 = TNode(4), TNode(9), TNode(13)
    T3, T4 = TNode(1), TNode(6, T7, None)
    T5, T6 = TNode(11, T8, T9), TNode(20)
    T1, T2 = TNode(3, T3, T4), TNode(15, T5, T6)
    T0 = TNode(8, T1, T2)

    print(height(T0))
    print(is_bst(T0))
    print(is_balanced(T0))
    print(common_ancestors(T0, T6, T8))
    print(lca(T0, T1, T7))

    T7, T8, T9, T10 = TNode(4), TNode(5), TNode(1), TNode(4)
    T3, T4 = TNode(3), TNode(6, T7, T8)
    T5, T6 = TNode(5, None, T9), TNode(5, T10, None)
    T1, T2 = TNode(6, T3, T4), TNode(7, T5, T6)
    T0 = TNode(8, T1, T2)

    print(height(T0))
    print(is_bst(T0))
    print(is_balanced(T0))
    print(common_ancestors(T0, T6, T8))
    print(lca(T0, T1, T7))

    T7, T8, T9= TNode(7), TNode(5), TNode(9)
    T3, T4 = TNode(1), TNode(4, T7, None)
    T5, T6 = TNode(20, T8, T9), TNode(6)
    T1, T2 = TNode(3, T3, T4), TNode(15, T5, T6)
    T0 = TNode(8, T1, T2)

    print(height(T0))
    print(is_bst(T0))
    print(is_balanced(T0))
    print(common_ancestors(T0, T6, T8))
    print(lca(T0, T1, T7))
