import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        """
        이 함수는 주어진 돌들의 무게를 사용하여 마지막에 남는 돌의 무게를 반환합니다.
        가장 무거운 두 돌을 선택하여 부수는 과정을 반복합니다.
        """
        
        # 최대 힙을 사용하기 위해 모든 돌의 무게를 음수로 변환하여 힙에 삽입
        max_heap = [-stone for stone in stones]
        heapq.heapify(max_heap)  # 힙 구조로 변환
        
        while len(max_heap) > 1:
            # 가장 무거운 두 돌을 추출
            first = heapq.heappop(max_heap)  # 가장 무거운 돌
            second = heapq.heappop(max_heap) # 두 번째로 무거운 돌
            
            if first != second:
                # 두 돌의 무게가 다르면, 남은 돌의 무게를 다시 힙에 삽입
                heapq.heappush(max_heap, first - second)
        
        # 마지막에 남은 돌이 있으면 그 무게를 반환 (음수이므로 양수로 변환)
        return -max_heap[0] if max_heap else 0
