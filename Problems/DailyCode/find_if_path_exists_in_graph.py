# 문제 설명:
#
# N개의 정점이 있는 양방향 그래프가 주어집니다. 각 정점은 0부터 N-1까지 번호가 매겨져 있습니다.
# 그래프의 간선은 2차원 정수 배열 edges로 표현되며, 각 edges[i] = [ui, vi]는 정점 ui와 vi 사이에
# 양방향 간선이 있음을 나타냅니다. 모든 정점 쌍은 최대 하나의 간선으로 연결되어 있으며,
# 자기 자신으로의 간선은 존재하지 않습니다.
#
# 주어진 edges와 정수 n, source, destination에 대해, source 정점에서 destination 정점으로
# 가는 유효한 경로가 존재하는지 여부를 판단하여 반환합니다.
#
# 예를 들어:
#
# 예제 1:
# 입력: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
# 출력: True
# 설명: 정점 0에서 정점 2로 가는 경로가 두 개 있습니다: 0 → 1 → 2 또는 0 → 2
#
# 예제 2:
# 입력: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
# 출력: False
# 설명: 정점 0에서 정점 5로 가는 경로가 존재하지 않습니다.
#
# 제약 조건:
# - 1 <= n <= 2 * 10^5
# - 0 <= edges.length <= 2 * 10^5
# - edges[i].length == 2
# - 0 <= ui, vi <= n - 1
# - ui != vi
# - 0 <= source, destination <= n - 1
# - 중복 간선은 존재하지 않습니다.
# - 자기 자신으로의 간선은 존재하지 않습니다.

from typing import List
from collections import deque

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        """
        주어진 양방향 그래프에서 source 정점에서 destination 정점으로 가는 유효한 경로가 있는지 확인합니다.
        
        :param n: 정점의 개수
        :param edges: 간선을 나타내는 2차원 리스트
        :param source: 시작 정점
        :param destination: 도착 정점
        :return: 경로가 존재하면 True, 아니면 False
        """
        if source == destination:
            return True  # 시작과 도착이 같으면 항상 경로가 존재

        # 인접 리스트 생성
        adjacency = [[] for _ in range(n)]
        for u, v in edges:
            adjacency[u].append(v)
            adjacency[v].append(u)
        
        # BFS를 위한 큐와 방문 리스트 초기화
        queue = deque([source])
        visited = [False] * n
        visited[source] = True
        
        while queue:
            current = queue.popleft()
            for neighbor in adjacency[current]:
                if not visited[neighbor]:
                    if neighbor == destination:
                        return True  # 도착 정점에 도달하면 True 반환
                    visited[neighbor] = True
                    queue.append(neighbor)
        
        return False  # 모든 가능한 경로를 탐색했으나 도착 정점에 도달하지 못함

# 테스트를 위한 헬퍼 함수
def run_test_case(test_num, n, edges, source, destination, expected):
    solution = Solution()
    result = solution.validPath(n, edges, source, destination)
    print(f"Test Case {test_num}:")
    print(f"Input: n = {n}, edges = {edges}, source = {source}, destination = {destination}")
    print(f"Expected Output: {expected}")
    print(f"Actual Output: {result}")
    print("PASS" if result == expected else "FAIL")
    print("-" * 50)

# 메인 함수: 솔루션 테스트
def main():
    # 테스트 케이스 목록
    test_cases = [
        {
            'test_num': 1,
            'n': 3,
            'edges': [[0,1],[1,2],[2,0]],
            'source': 0,
            'destination': 2,
            'expected': True
        },
        {
            'test_num': 2,
            'n': 6,
            'edges': [[0,1],[0,2],[3,5],[5,4],[4,3]],
            'source': 0,
            'destination': 5,
            'expected': False
        },
        {
            'test_num': 3,
            'n': 1,
            'edges': [],
            'source': 0,
            'destination': 0,
            'expected': True
        },
        {
            'test_num': 4,
            'n': 4,
            'edges': [[0,1],[1,2],[2,3]],
            'source': 0,
            'destination': 3,
            'expected': True
        },
        {
            'test_num': 5,
            'n': 5,
            'edges': [[0,1],[1,2],[3,4]],
            'source': 0,
            'destination': 4,
            'expected': False
        },
        {
            'test_num': 6,
            'n': 7,
            'edges': [[0,1],[0,2],[1,3],[1,4],[2,5],[5,6]],
            'source': 3,
            'destination': 6,
            'expected': True
        },
        {
            'test_num': 7,
            'n': 2,
            'edges': [],
            'source': 0,
            'destination': 1,
            'expected': False
        },
        {
            'test_num': 8,
            'n': 4,
            'edges': [[0,1],[1,2],[2,3],[3,0]],
            'source': 0,
            'destination': 2,
            'expected': True
        },
        {
            'test_num': 9,
            'n': 5,
            'edges': [[0,1],[1,2],[2,3],[3,4]],
            'source': 0,
            'destination': 4,
            'expected': True
        },
        {
            'test_num': 10,
            'n': 5,
            'edges': [[0,1],[1,2],[3,4]],
            'source': 0,
            'destination': 4,
            'expected': False
        },
    ]
    
    # 각 테스트 케이스 실행
    for test in test_cases:
        run_test_case(
            test['test_num'],
            test['n'],
            test['edges'],
            test['source'],
            test['destination'],
            test['expected']
        )

if __name__ == "__main__":
    main()

"""
프로그램 실행 결과:

Test Case 1:
Input: n = 3, edges = [[0, 1], [1, 2], [2, 0]], source = 0, destination = 2
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 2:
Input: n = 6, edges = [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]], source = 0, destination = 5
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
Test Case 3:
Input: n = 1, edges = [], source = 0, destination = 0
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 4:
Input: n = 4, edges = [[0, 1], [1, 2], [2, 3]], source = 0, destination = 3
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 5:
Input: n = 5, edges = [[0, 1], [1, 2], [3, 4]], source = 0, destination = 4
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
Test Case 6:
Input: n = 7, edges = [[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [5, 6]], source = 3, destination = 6
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 7:
Input: n = 2, edges = [], source = 0, destination = 1
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
Test Case 8:
Input: n = 4, edges = [[0, 1], [1, 2], [2, 3], [3, 0]], source = 0, destination = 2
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 9:
Input: n = 5, edges = [[0, 1], [1, 2], [2, 3], [3, 4]], source = 0, destination = 4
Expected Output: True
Actual Output: True
PASS
--------------------------------------------------
Test Case 10:
Input: n = 5, edges = [[0, 1], [1, 2], [3, 4]], source = 0, destination = 4
Expected Output: False
Actual Output: False
PASS
--------------------------------------------------
Additional Test Case 11:
Operations: ["MyCircularDeque", "insertFront", "insertLast", "deleteFront", "getFront", "isEmpty"]
Inputs: [[2], [10], [20], [], [], []]
Expected Output: [None, True, True, True, 20, False]
Actual Output:   [None, True, True, True, 20, False]
PASS
--------------------------------------------------
Additional Test Case 12:
Operations: ["MyCircularDeque", "insertLast", "insertLast", "deleteFront", "getFront", "getRear"]
Inputs: [[3], [1], [2], [], [], []]
Expected Output: [None, True, True, True, 2, 2]
Actual Output:   [None, True, True, True, 2, 2]
PASS
--------------------------------------------------
"""
