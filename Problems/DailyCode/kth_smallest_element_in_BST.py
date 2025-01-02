"""
문제 설명:

이진 탐색 트리(Binary Search Tree, BST)의 루트 노드(root)와 정수 k가 주어질 때, 트리의 모든 노드 값들 중에서 k번째로 작은 값을 반환하는 문제입니다.
트리의 노드 값들은 중복되지 않으며, BST의 특성상 왼쪽 서브트리의 모든 노드 값은 현재 노드 값보다 작고, 오른쪽 서브트리의 모든 노드 값은 현재 노드 값보다 큽니다.

예를 들어, 다음과 같은 BST가 주어졌을 때:
    3
   / \
  1   4
   \
    2

k = 1일 경우, 가장 작은 값은 1이므로 출력은 1이 됩니다.
k = 3일 경우, 세 번째로 작은 값은 3이므로 출력은 3이 됩니다.

제약 조건:
- 트리의 노드 개수는 n이며, 1 <= k <= n <= 10^4입니다.
- 각 노드의 값은 0 <= Node.val <= 10^4입니다.
- 트리는 유효한 이진 탐색 트리입니다.

추가 질문:
만약 BST가 자주 수정(insert 및 delete 연산)이 이루어지고, k번째 작은 값을 자주 찾아야 한다면 어떻게 최적화할 수 있을까요?

해결 방법:
BST에서 k번째 작은 값을 찾기 위해서는 중위 순회(Inorder Traversal)를 이용하는 것이 일반적입니다. 중위 순회는 트리를 오름차순으로 방문하므로, k번째로 작은 값을 쉽게 찾을 수 있습니다. 그러나 트리가 자주 수정되는 경우, 매번 중위 순회를 수행하는 것은 비효율적일 수 있습니다. 이럴 때는 각 노드에 서브트리의 노드 개수를 저장하여, 이를 기반으로 k번째 작은 값을 더 효율적으로 찾을 수 있습니다.

"""

from typing import Optional, List
from collections import deque

# 이진 트리 노드의 정의
class TreeNode:
    def __init__(self, val: int = 0, left: 'Optional[TreeNode]' = None, right: 'Optional[TreeNode]' = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
        주어진 이진 탐색 트리에서 k번째로 작은 값을 찾습니다.
        
        :param root: 이진 탐색 트리의 루트 노드
        :param k: 찾고자 하는 k번째 순위
        :return: k번째로 작은 노드의 값
        """
        # 중위 순회를 사용하여 BST의 노드들을 오름차순으로 방문
        stack = []
        current = root
        count = 0  # 현재까지 방문한 노드의 개수
        
        while stack or current:
            # 가장 왼쪽 노드로 이동
            while current:
                stack.append(current)
                current = current.left
            current = stack.pop()
            count += 1
            if count == k:
                return current.val
            current = current.right
        
        return -1  # k가 유효한 범위를 벗어날 경우 (문제의 제약 조건에 따라 발생하지 않음)

# 테스트를 위한 헬퍼 함수
def build_bst_from_level_order(data: List[Optional[int]]) -> Optional[TreeNode]:
    """
    레벨 순서(level order)로 주어진 데이터를 기반으로 BST를 생성합니다.
    
    :param data: 레벨 순서로 주어진 노드 값들의 리스트 (None은 노드의 부재를 의미)
    :return: 생성된 BST의 루트 노드
    """
    if not data:
        return None
    iter_data = iter(data)
    root_val = next(iter_data)
    if root_val is None:
        return None
    root = TreeNode(root_val)
    queue = deque([root])
    while queue:
        node = queue.popleft()
        try:
            left_val = next(iter_data)
            if left_val is not None:
                node.left = TreeNode(left_val)
                queue.append(node.left)
            right_val = next(iter_data)
            if right_val is not None:
                node.right = TreeNode(right_val)
                queue.append(node.right)
        except StopIteration:
            break
    return root

# 테스트 케이스 실행 함수
def run_test_case(test_num: int, data: List[Optional[int]], k: int, expected: int):
    """
    주어진 테스트 케이스를 실행하고 결과를 출력합니다.
    
    :param test_num: 테스트 케이스 번호
    :param data: BST를 구성하는 레벨 순서 데이터
    :param k: 찾고자 하는 k번째 순위
    :param expected: 예상되는 결과 값
    """
    root = build_bst_from_level_order(data)
    solution = Solution()
    result = solution.kthSmallest(root, k)
    print(f"테스트 케이스 {test_num}:")
    print(f"입력: root = {data}, k = {k}")
    print(f"예상 출력: {expected}")
    print(f"실제 출력: {result}")
    print("PASS" if result == expected else "FAIL")
    print("-" * 50)

# 메인 함수: 솔루션 테스트
def main():
    test_cases = [
        {
            'test_num': 1,
            'data': [3,1,4,None,2],
            'k': 1,
            'expected': 1
        },
        {
            'test_num': 2,
            'data': [5,3,6,2,4,None,None,1],
            'k': 3,
            'expected': 3
        },
        {
            'test_num': 3,
            'data': [1],
            'k': 1,
            'expected': 1
        },
        {
            'test_num': 4,
            'data': [2,1,3],
            'k': 2,
            'expected': 2
        },
        {
            'test_num': 5,
            'data': [5,3,6,2,4,None,None,1],
            'k': 3,
            'expected': 3
        },
        {
            'test_num': 6,
            'data': [7,3,15,None,9,20],
            'k': 2,
            'expected': 7
        },
        {
            'test_num': 7,
            'data': [3,1,4,None,2],
            'k': 2,
            'expected': 2
        },
        {
            'test_num': 8,
            'data': [3,1,4,None,2,None,None],
            'k': 4,
            'expected': 4
        },
        {
            'test_num': 9,
            'data': [1, None, 2],
            'k': 1,
            'expected': 1
        },
        {
            'test_num': 10,
            'data': [1, None, 2, None, 3, None, 4, None, 5],
            'k': 5,
            'expected': 5
        },
    ]
    
    for test in test_cases:
        run_test_case(
            test['test_num'],
            test['data'],
            test['k'],
            test['expected']
        )

if __name__ == "__main__":
    main()
