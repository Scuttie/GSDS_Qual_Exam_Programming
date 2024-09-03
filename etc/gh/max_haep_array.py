from collections import deque

class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_complete_tree(root):
    """완전 이진 트리인지 확인"""
    if not root:
        return True

    queue = deque([root])
    end = False  # 완전 이진 트리의 끝을 확인

    while queue:
        node = queue.popleft()

        if node is None:
            end = True
        else:
            if end:  # 이미 None을 만난 후에 다시 노드를 만나면 완전 이진 트리가 아님
                return False
            queue.append(node.left)
            queue.append(node.right)

    return True

def is_max_heap(root):
    """Max Heap 속성을 만족하는지 확인"""
    if not root:
        return True

    queue = deque([root])

    while queue:
        node = queue.popleft()

        if node.left:
            if node.val < node.left.val:
                return False
            queue.append(node.left)

        if node.right:
            if node.val < node.right.val:
                return False
            queue.append(node.right)

    return True

def is_max_heap_tree(root):
    """트리가 완전 이진 트리이며 Max Heap 속성을 만족하는지 확인"""
    return is_complete_tree(root) and is_max_heap(root)

def tree_to_array(root):
    """트리를 레벨 순서대로 배열로 변환"""
    if not root:
        return []

    array = []
    queue = deque([root])

    while queue:
        node = queue.popleft()
        array.append(node.val)

        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

    return array

# 사용 예시
root = TNode(40)
root.left = TNode(30)
root.right = TNode(20)
root.left.left = TNode(10)
root.left.right = TNode(15)
root.right.left = TNode(5)
root.right.right = TNode(1)

if is_max_heap_tree(root):
    print("Given tree is a Max Heap.")
else:
    print("Given tree is NOT a Max Heap.")

array_representation = tree_to_array(root)
print("Tree as array:", array_representation)
