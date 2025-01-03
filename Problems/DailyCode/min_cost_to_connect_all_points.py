from typing import List
import heapq

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        """
        이 함수는 주어진 2D 평면상의 점들을 연결하는 데 필요한 최소 비용을 계산합니다.
        비용은 맨해튼 거리(|xi - xj| + |yi - yj|)로 정의됩니다.
        모든 점이 연결되도록 하는 최소 비용을 반환합니다.
        """
        
        n = len(points)  # 총 점의 개수
        if n == 0:
            return 0  # 점이 없으면 비용은 0

        # 방문 여부를 추적하기 위한 리스트, 초기에는 모든 점이 방문되지 않음
        visited = [False] * n
        min_cost = 0  # 총 최소 비용
        edges = []  # 최소 힙을 위한 우선순위 큐 (비용, 점의 인덱)

        # 첫 번째 점을 방문 처리하고, 이 점과 다른 모든 점 간의 거리를 힙에 추가
        visited[0] = True
        for i in range(1, n):
            distance = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1])
            heapq.heappush(edges, (distance, i))

        # 연결된 점의 개수를 추적하기 위한 변수, 시작점은 이미 연결됨
        connected = 1

        while connected < n:
            # 힙에서 가장 작은 비용의 간선을 선택
            cost, next_point = heapq.heappop(edges)
            
            # 선택된 점이 아직 방문되지 않았다면 연결
            if not visited[next_point]:
                visited[next_point] = True  # 점을 방문 처리
                min_cost += cost  # 비용을 누적
                connected += 1  # 연결된 점의 수 증가

                # 새로 연결된 점과 다른 모든 점 간의 거리를 힙에 추가
                for i in range(n):
                    if not visited[i]:
                        new_distance = abs(points[next_point][0] - points[i][0]) + abs(points[next_point][1] - points[i][1])
                        heapq.heappush(edges, (new_distance, i))

        return min_cost  # 모든 점이 연결된 후의 총 최소 비용
