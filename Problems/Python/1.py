class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

#(a)
def is_max_heap(T: TNode) -> bool:
    if not T:
        return True
    left_heap = True
    right_heap = True
    if T.left:
        left_heap = T.val >= T.left.val
    if T.right:
        right_heap = T.val >= T.right.val
    
    return left_heap and right_heap and is_max_heap(T.left) and is_max_heap(T.right)
    

#(b)
#input binary tree가 heap property를 만족 안할수도 있는데 바꾸는건 아니고 그냥 넣으면 되는건가?
def binary_tree_to_heap_array(T: TNode) -> list[int]:
    heap_array = []

    queue = [T]
    while queue:
        cur_node = queue[0]
        if cur_node.left:
            queue.append(cur_node.left)
        if cur_node.right:
            queue.append(cur_node.right)
        heap_array.append(cur_node.val)
        queue = queue[1:]
    return heap_array






# not satisfy max heap property
T7, T8, T9, T10 = TNode(4), TNode(6), TNode(5), TNode(5)
T3, T4 = TNode(3), TNode(6, T7, T8)
T5, T6 = TNode(1, None, T9), TNode(4, T10, None)
T1, T2 = TNode(5, T3, T4), TNode(7, T5, T6)
T0 = TNode(8, T1, T2)
# satisfy max heap property
'''T7, T8, T9, T10 = TNode(4), TNode(5), TNode(1), TNode(4)
T3, T4 = TNode(3), TNode(6, T7, T8)
T5, T6 = TNode(5, None, T9), TNode(5, T10, None)
T1, T2 = TNode(6, T3, T4), TNode(7, T5, T6)
T0 = TNode(8, T1, T2)'''

print(is_max_heap(T0))
print(binary_tree_to_heap_array(T0))

