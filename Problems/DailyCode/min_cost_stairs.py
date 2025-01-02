from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        """
        계단을 오르는 최소 비용을 계산합니다.
        각 계단을 오를 때마다 해당 계단의 비용을 지불해야 하며, 
        한 번에 한 계단 또는 두 계단을 오를 수 있습니다.
        시작점은 인덱스 0 또는 인덱스 1에서 선택할 수 있습니다.

        매개변수:
        cost (List[int]): 각 계단을 오르는 데 드는 비용을 담은 리스트

        반환값:
        int: 계단 꼭대기에 도달하기 위한 최소 비용
        """
        
        n = len(cost)  # 계단의 총 개수

        # 초기 두 계단의 최소 비용 설정
        prev1 = cost[0]  # 이전 계단(인덱스 0)의 비용
        prev2 = cost[1]  # 이전 이전 계단(인덱스 1)의 비용

        # 계단이 두 개일 경우, 최소 비용은 두 계단 중 더 작은 비용
        if n == 2:
            return min(prev1, prev2)
        
        # 세 번째 계단부터 마지막 계단까지 반복
        for i in range(2, n):
            # 현재 계단까지의 최소 비용 계산
            current = min(prev1, prev2) + cost[i]
            # 이전 두 계단의 비용 업데이트
            prev1, prev2 = prev2, current
        
        # 꼭대기에 도달하기 위해 마지막 계단이나 마지막에서 두 번째 계단 중 더 작은 비용을 선택
        return min(prev1, prev2)

# 예제 테스트
if __name__ == "__main__":
    solution = Solution()
    
    # 예제 1
    cost1 = [10, 15, 20]
    print("예제 1 출력:", solution.minCostClimbingStairs(cost1))  # 출력: 15
    
    # 예제 2
    cost2 = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    print("예제 2 출력:", solution.minCostClimbingStairs(cost2))  # 출력: 6
    
    # 추가 예제 3
    cost3 = [0, 0, 0, 0]
    print("예제 3 출력:", solution.minCostClimbingStairs(cost3))  # 출력: 0
