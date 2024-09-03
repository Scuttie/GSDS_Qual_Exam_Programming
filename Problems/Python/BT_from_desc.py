# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def createBinaryTree(self, descriptions):
        """
        :type descriptions: List[List[int]]
        :rtype: Optional[TreeNode]
        """
        values = {}  # 각 노드의 값을 저장할 딕셔너리
        child_set = set()  # 자식 노드를 추적하기 위한 집합

        # 모든 노드를 생성하고 부모-자식 관계 설정
        for parent, child, is_left in descriptions:
            if parent not in values:
                values[parent] = TreeNode(parent)  # 부모 노드가 없으면 생성
            if child not in values:
                values[child] = TreeNode(child)  # 자식 노드가 없으면 생성

            child_set.add(child)  # 자식 노드를 집합에 추가

            # 부모-자식 관계 설정
            if is_left == 1:
                values[parent].left = values[child]  # 왼쪽 자식으로 설정
            else:
                values[parent].right = values[child]  # 오른쪽 자식으로 설정

        # 루트 노드를 찾기 위해, 자식으로 등장하지 않은 노드를 찾음
        head = None
        for value in values.keys():
            if value not in child_set:
                head = values[value]
                break

        return head

descriptions = [
    [1, 2, 1],
    [1, 3, 0],
    [2, 4, 1]
]

solution = Solution()
root = solution.createBinaryTree(descriptions)

# 이진 트리를 출력하는 간단한 함수 (예시)
def print_tree(node):
    if not node:
        return
    print(node.val)
    print_tree(node.left)
    print_tree(node.right)

print_tree(root)

