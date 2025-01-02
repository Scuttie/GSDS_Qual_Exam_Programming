"""
문제 설명:

비방향 그래프가 n개의 노드로 구성되어 있으며, 각 노드는 0부터 n-1까지 번호가 매겨져 있습니다.
2차원 배열 graph가 주어지며, graph[u]는 노드 u에 인접한 노드들의 배열을 나타냅니다.
즉, graph[u]의 각 v에 대해 노드 u와 노드 v 사이에 비방향 간선이 존재합니다.

그래프는 다음과 같은 특성을 가집니다:
- 자기 자신으로의 간선은 존재하지 않습니다. (graph[u]에는 u가 포함되지 않습니다.)
- 병렬 간선은 존재하지 않습니다. (graph[u]에는 중복된 값이 없습니다.)
- 그래프는 연결되어 있지 않을 수 있습니다. 즉, 어떤 두 노드 u와 v에 대해 u에서 v로 가는 경로가 없을 수 있습니다.

이 그래프가 이분 그래프(bipartite)인지 여부를 판단해야 합니다.
이분 그래프란 노드들을 두 개의 독립 집합 A와 B로 분할할 수 있어,
모든 간선이 집합 A에 속한 노드와 집합 B에 속한 노드를 연결하는 그래프를 말합니다.

입력 형식:
- graph.length == n
- 1 <= n <= 100
- 0 <= graph[u].length < n
- 0 <= graph[u][i] <= n - 1
- graph[u]는 u를 포함하지 않습니다.
- graph[u]의 모든 값은 고유합니다.
- 만약 graph[u]에 v가 포함되어 있다면, graph[v]에도 u가 포함됩니다.

출력 형식:
- 그래프가 이분 그래프라면 True, 그렇지 않으면 False를 반환합니다.

예제 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: False
설명: 노드들을 두 집합으로 분할할 수 없으므로 이분 그래프가 아닙니다.

예제 2:
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: True
설명: 노드들을 {0,2}와 {1,3}로 분할할 수 있으므로 이분 그래프입니다.

제약 조건:
- graph.length == n
- 1 <= n <= 100
- 0 <= graph[u].length < n
- 0 <= graph[u][i] <= n - 1
- graph[u]는 u를 포함하지 않습니다.
- graph[u]의 모든 값은 고유합니다.
- 만약 graph[u]에 v가 포함되어 있다면, graph[v]에도 u가 포함됩니다.

해결 방법:
이분 그래프 여부는 그래프를 두 개의 색상으로 칠할 수 있는지 여부와 같습니다.
BFS(너비 우선 탐색) 또는 DFS(깊이 우선 탐색)를 사용하여 그래프의 각 노드를 두 색상 중 하나로 색칠하면서,
인접한 노드가 다른 색을 가지도록 할 수 있는지 확인합니다.
만약 어떤 인접한 노드들이 같은 색을 가져야 한다면, 그래프는 이분 그래프가 아닙니다.

"""

from typing import List
from collections import deque

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        """
        주어진 비방향 그래프가 이분 그래프인지 여부를 판단합니다.
        
        :param graph: 비방향 그래프를 나타내는 2차원 리스트
        :return: 그래프가 이분 그래프이면 True, 아니면 False
        """
        n = len(graph)
        color = [ -1 ] * n  # 각 노드의 색상: -1은 아직 색칠하지 않음을 의미
        
        for node in range(n):
            if color[node] == -1:
                # BFS를 사용하여 색칠 시작
                queue = deque()
                queue.append(node)
                color[node] = 0  # 첫 번째 색상으로 색칠
                
                while queue:
                    current = queue.popleft()
                    for neighbor in graph[current]:
                        if color[neighbor] == -1:
                            # 이웃 노드에 반대 색상 할당
                            color[neighbor] = 1 - color[current]
                            queue.append(neighbor)
                        elif color[neighbor] == color[current]:
                            # 같은 색상을 가진 인접 노드 발견: 이분 그래프 아님
                            return False
        return True  # 모든 노드를 성공적으로 색칠: 이분 그래프임

# 테스트를 위한 헬퍼 함수
def run_test_case(test_num, graph, expected):
    solution = Solution()
    result = solution.isBipartite(graph)
    print(f"Test Case {test_num}:")
    print(f"Input: graph = {graph}")
    print(f"Expected Output: {expected}")
    print(f"Actual Output: {result}")
    print("PASS" if result == expected else "FAIL")
    print("-" * 50)

# 메인 함수: 솔루션 테스트
def main():
    # 테스트 케이스 목록
    test_cases = [
        # 예제 테스트 케이스 1:
        {
            'test_num': 1,
            'graph': [[1,2,3],[0,2],[0,1,3],[0,2]],
            'expected': False
        },
        # 예제 테스트 케이스 2:
        {
            'test_num': 2,
            'graph': [[1,3],[0,2],[1,3],[0,2]],
            'expected': True
        },
        # 추가 테스트 케이스 3:
        {
            'test_num': 3,
            'graph': [[1],[0,3],[3],[1]],
            'expected': True
        },
        # 추가 테스트 케이스 4:
        {
            'test_num': 4,
            'graph': [[1,2],[0,2],[0,1,3],[2]],
            'expected': False
        },
        # 추가 테스트 케이스 5:
        {
            'test_num': 5,
            'graph': [[]],
            'expected': True
        },
        # 추가 테스트 케이스 6:
        {
            'test_num': 6,
            'graph': [[1,3],[0,2],[1,3],[0,2],[5],[4]],
            'expected': True
        },
        # 추가 테스트 케이스 7:
        {
            'test_num': 7,
            'graph': [[1],[0,2,3],[1,3],[1,2]],
            'expected': False
        },
        # 추가 테스트 케이스 8:
        {
            'test_num': 8,
            'graph': [[1,4],[0,2],[1,3],[2,4],[0,3]],
            'expected': False
        },
        # 추가 테스트 케이스 9:
        {
            'test_num': 9,
            'graph': [[1],[0]],
            'expected': True
        },
        # 추가 테스트 케이스 10:
        {
            'test_num': 10,
            'graph': [[1,2,3],[0],[0],[0]],
            'expected': False
        },
    ]
    
    # 각 테스트 케이스 실행
    for test in test_cases:
        run_test_case(
            test['test_num'],
            test['graph'],
            test['expected']
        )

if __name__ == "__main__":
    main()

"""
프로그램 실행 결과:

Test Case 1:
Input: graph = [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
Test Case 2:
Input: graph = [[1, 3], [0, 2], [1, 3], [0, 2]]
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 3:
Input: graph = [[1], [0, 3], [3], [1]]
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 4:
Input: graph = [[1, 2], [0, 2], [0, 1, 3], [2]]
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
Test Case 5:
Input: graph = [[]]
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 6:
Input: graph = [[1, 3], [0, 2], [1, 3], [0, 2], [5], [4]]
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 7:
Input: graph = [[1], [0, 2, 3], [1, 3], [1, 2]]
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
Test Case 8:
Input: graph = [[1, 4], [0, 2], [1, 3], [2, 4], [0, 3]]
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
Test Case 9:
Input: graph = [[1], [0]]
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 10:
Input: graph = [[1, 2, 3], [0], [0], [0]]
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
"""
