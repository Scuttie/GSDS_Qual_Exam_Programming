# 프로그램 설명:
# 이 프로그램은 이진 트리의 모든 왼쪽 리프 노드의 합을 계산합니다.
# 리프 노드는 자식이 없는 노드를 의미하며, 왼쪽 리프 노드는 부모 노드의 왼쪽 자식이면서 리프인 노드를 말합니다.
# 예를 들어, 트리가 다음과 같을 때:
#
#         3
#        / \
#       9  20
#          /  \
#        15    7
#
# 왼쪽 리프 노드는 9와 15이며, 이들의 합은 24입니다.

from typing import Optional

# 이진 트리 노드의 정의
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        """
        TreeNode 클래스는 이진 트리의 각 노드를 나타냅니다.

        :param val: 노드의 값 (기본값: 0)
        :param left: 왼쪽 자식 노드 (기본값: None)
        :param right: 오른쪽 자식 노드 (기본값: None)
        """
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        """
        주어진 이진 트리의 모든 왼쪽 리프 노드의 합을 계산합니다.

        :param root: 이진 트리의 루트 노드
        :return: 왼쪽 리프 노드의 합
        """
        def is_leaf(node: TreeNode) -> bool:
            """
            주어진 노드가 리프 노드인지 확인합니다.

            :param node: 확인할 노드
            :return: 리프 노드이면 True, 아니면 False
            """
            return node.left is None and node.right is None

        def dfs(node: Optional[TreeNode], is_left: bool) -> int:
            """
            깊이 우선 탐색(DFS)을 사용하여 왼쪽 리프 노드의 합을 계산합니다.

            :param node: 현재 탐색 중인 노드
            :param is_left: 현재 노드가 부모의 왼쪽 자식인지 여부
            :return: 왼쪽 리프 노드의 합
            """
            if node is None:
                # 노드가 없으면 합에 아무것도 더하지 않습니다.
                return 0

            if is_leaf(node):
                if is_left:
                    # 현재 노드가 왼쪽 리프 노드라면, 그 값을 합에 더합니다.
                    return node.val
                else:
                    # 현재 노드가 오른쪽 리프 노드라면, 무시합니다.
                    return 0

            # 현재 노드가 리프 노드가 아니라면, 왼쪽과 오른쪽 자식을 재귀적으로 탐색합니다.
            left_sum = dfs(node.left, True)    # 왼쪽 자식은 왼쪽으로 표시
            right_sum = dfs(node.right, False) # 오른쪽 자식은 오른쪽으로 표시

            # 왼쪽 리프 노드의 합과 오른쪽 리프 노드의 합을 더하여 반환합니다.
            return left_sum + right_sum

        # 루트 노드는 왼쪽도 오른쪽도 아니므로, is_left는 False로 시작합니다.
        return dfs(root, False)

# 테스트를 위한 헬퍼 함수
def build_tree_from_list(values):
    """
    리스트를 사용하여 이진 트리를 구축합니다. 리스트는 레벨 순서(level order)를 따릅니다.
    'None' 값은 해당 위치에 노드가 없음을 나타냅니다.

    :param values: 이진 트리를 나타내는 리스트
    :return: 이진 트리의 루트 노드
    """
    if not values:
        return None

    # 노드 인스턴스를 저장할 리스트
    nodes = [None if val is None else TreeNode(val) for val in values]

    # 자식 노드를 연결
    kids = nodes[::-1]
    root = kids.pop()

    for node in nodes:
        if node:
            if kids:
                node.left = kids.pop()
            if kids:
                node.right = kids.pop()

    return root

# 메인 함수: 예제 테스트 케이스를 실행
if __name__ == "__main__":
    # 예제 1:
    # Input: root = [3,9,20,None,None,15,7]
    # Output: 24
    # 설명: 왼쪽 리프 노드는 9와 15, 합은 24
    tree_values1 = [3, 9, 20, None, None, 15, 7]
    root1 = build_tree_from_list(tree_values1)
    solution = Solution()
    result1 = solution.sumOfLeftLeaves(root1)
    print("Test Case 1:")
    print("왼쪽 리프 노드의 합:", result1)  # 예상 출력: 24
    print("Expected Output: 24")
    print("PASS" if result1 == 24 else "FAIL")
    print()

    # 예제 2:
    # Input: root = [1]
    # Output: 0
    # 설명: 리프 노드는 1개뿐이며, 왼쪽 자식이 아니므로 합은 0
    tree_values2 = [1]
    root2 = build_tree_from_list(tree_values2)
    result2 = solution.sumOfLeftLeaves(root2)
    print("Test Case 2:")
    print("왼쪽 리프 노드의 합:", result2)  # 예상 출력: 0
    print("Expected Output: 0")
    print("PASS" if result2 == 0 else "FAIL")
    print()

    # 추가 테스트 케이스 1:
    # 트리 구조:
    #         5
    #        / \
    #       3   8
    #      /   / \
    #     2   7   9
    #        /
    #       1
    # 왼쪽 리프 노드: 2, 1
    # 합: 3
    tree_values3 = [5, 3, 8, 2, None, 7, 9, None, None, 1]
    root3 = build_tree_from_list(tree_values3)
    result3 = solution.sumOfLeftLeaves(root3)
    print("Test Case 3:")
    print("왼쪽 리프 노드의 합:", result3)  # 예상 출력: 3 (2 + 1)
    print("Expected Output: 3")
    print("PASS" if result3 == 3 else "FAIL")
    print()

    # 추가 테스트 케이스 2:
    # 트리 구조:
    #         -1
    #        /  \
    #      -2    -3
    #      /       \
    #    -4        -5
    # 왼쪽 리프 노드: -4
    # 합: -4
    tree_values4 = [-1, -2, -3, -4, None, None, -5]
    root4 = build_tree_from_list(tree_values4)
    result4 = solution.sumOfLeftLeaves(root4)
    print("Test Case 4:")
    print("왼쪽 리프 노드의 합:", result4)  # 예상 출력: -4
    print("Expected Output: -4")
    print("PASS" if result4 == -4 else "FAIL")
    print()

    # 추가 테스트 케이스 3:
    # 트리 구조:
    #         0
    #        / \
    #       1   2
    #      /   / \
    #     3   4   5
    #    /     \
    #   6       7
    # 왼쪽 리프 노드: 6, 7, 5
    # 합: 6 + 7 + 5 = 18 (단, 5는 오른쪽 리프 노드이므로 제외)
    # 실제 왼쪽 리프 노드는 6와 7, 합은 13
    tree_values5 = [0, 1, 2, 3, None, 4, 5, 6, None, None, 7]
    root5 = build_tree_from_list(tree_values5)
    result5 = solution.sumOfLeftLeaves(root5)
    print("Test Case 5:")
    print("왼쪽 리프 노드의 합:", result5)  # 예상 출력: 13 (6 + 7)
    print("Expected Output: 13")
    print("PASS" if result5 == 13 else "FAIL")
    print()

    # 추가 테스트 케이스 4:
    # 트리 구조:
    #         10
    #        /  \
    #      5     15
    #     / \      \
    #    3   7      18
    # 왼쪽 리프 노드: 3, 18
    # 합: 3 + 18 = 21
    tree_values6 = [10, 5, 15, 3, 7, None, 18]
    root6 = build_tree_from_list(tree_values6)
    result6 = solution.sumOfLeftLeaves(root6)
    print("Test Case 6:")
    print("왼쪽 리프 노드의 합:", result6)  # 예상 출력: 21 (3 + 18)
    print("Expected Output: 21")
    print("PASS" if result6 == 21 else "FAIL")
    print()

    # 추가 테스트 케이스 5:
    # 트리 구조:
    #         1
    #          \
    #           2
    #            \
    #             3
    #              \
    #               4
    # 왼쪽 리프 노드: 없음
    # 합: 0
    tree_values7 = [1, None, 2, None, 3, None, 4]
    root7 = build_tree_from_list(tree_values7)
    result7 = solution.sumOfLeftLeaves(root7)
    print("Test Case 7:")
    print("왼쪽 리프 노드의 합:", result7)  # 예상 출력: 0
    print("Expected Output: 0")
    print("PASS" if result7 == 0 else "FAIL")
    print()

    # 추가 테스트 케이스 6:
    # 트리 구조:
    #         7
    #        / \
    #       3   8
    #      /   / \
    #     1   6   9
    #          \
    #           2
    # 왼쪽 리프 노드: 1, 2, 9
    # 합: 1 + 2 + 9 = 12 (단, 9는 오른쪽 리프 노드이므로 제외)
    # 실제 왼쪽 리프 노드는 1와 2, 합은 3
    tree_values8 = [7, 3, 8, 1, None, 6, 9, None, None, None, 2]
    root8 = build_tree_from_list(tree_values8)
    result8 = solution.sumOfLeftLeaves(root8)
    print("Test Case 8:")
    print("왼쪽 리프 노드의 합:", result8)  # 예상 출력: 3 (1 + 2)
    print("Expected Output: 3")
    print("PASS" if result8 == 3 else "FAIL")
    print()

    # 모든 테스트 케이스가 통과되었는지 확인
