from collections import deque

def is_max_heap(T: TNode) -> bool:
    if not T:
        return True
    
    q = deque([T])
    while q:
        current = q.popleft()
        # 왼쪽 자식 검사
        if current.left:
            if current.val < current.left.val:
                return False
            q.append(current.left)
        # 오른쪽 자식 검사
        if current.right:
            if current.val < current.right.val:
                return False
            q.append(current.right)
    
    return True

def binary_tree_to_heap_array(T: TNode) -> list[int]:
    if not T:
        return []
    
    from collections import deque
    q = deque([T])
    result = []
    
    while q:
        current = q.popleft()
        result.append(current.val)
        
        if current.left:
            q.append(current.left)
        if current.right:
            q.append(current.right)
    
    return result

class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 1) Max Heap Property를 만족하지 않는 예시 트리
#         8
#        /  \
#       5    7
#      / \  / \
#     3  6 1  4
#    / \    \
#   4  6     5
T7, T8, T9, T10 = TNode(4), TNode(6), TNode(5), TNode(5)
T3, T4 = TNode(3), TNode(6, T7, T8)
T5, T6 = TNode(1, None, T9), TNode(4, T10, None)
T1, T2 = TNode(5, T3, T4), TNode(7, T5, T6)
T0 = TNode(8, T1, T2)

print(is_max_heap(T0))                 # False (부모 노드 < 자식 노드인 부분이 존재)
print(binary_tree_to_heap_array(T0))   # [8, 5, 7, 3, 6, 1, 4, 4, 6, 5]

# 2) Max Heap Property를 만족하는 예시 트리
#         8
#        /  \
#       6    7
#      / \  / \
#     3  6 5  5
#    / \   \  /
#   4  5    1 4
T7, T8, T9, T10 = TNode(4), TNode(5), TNode(1), TNode(4)
T3, T4 = TNode(3), TNode(6, T7, T8)
T5, T6 = TNode(5, None, T9), TNode(5, T10, None)
T1, T2 = TNode(6, T3, T4), TNode(7, T5, T6)
T0 = TNode(8, T1, T2)

print(is_max_heap(T0))                 # True
print(binary_tree_to_heap_array(T0))   # [8, 6, 7, 3, 6, 5, 5, 4, 5, 1, 4]
