from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        """
        이 함수는 m x n 크기의 이진 행렬에서 모든 요소가 '1'인 가장 큰 정사각형의 넓이를 반환합니다.
        """
        
        if not matrix or not matrix[0]:
            return 0  # 행렬이 비어있으면 넓이는 0입니다.
        
        m = len(matrix)       # 행의 개수
        n = len(matrix[0])    # 열의 개수
        max_side = 0          # 최대 정사각형의 한 변의 길이
        dp = [[0] * (n + 1) for _ in range(m + 1)]  # DP 테이블 초기화 (m+1) x (n+1)
        
        # DP 테이블을 채워나갑니다.
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if matrix[i-1][j-1] == '1':
                    # 현재 위치에서 가능한 정사각형의 최대 크기를 결정합니다.
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    max_side = max(max_side, dp[i][j])  # 최대 정사각형 크자 업데이트
                # '0'인 경우 DP[i][j]는 0으로 유지됩니다.
        
        return max_side * max_side  # 최대 정사각형의 넓이를 반환합니다.
