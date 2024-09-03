class Solution(object):
    def findTheWinner(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        cnt = n  # 남은 사람의 수를 추적하는 카운터
        # 1부터 n까지의 숫자를 리스트로 생성 (게임에 참여하는 사람들)
        num_list = [i for i in range(1, n+1)]
        
        # 남은 사람이 1명보다 많을 동안 반복
        while cnt > 1:
            # 첫 번째 사람부터 k-1번째 사람까지를 리스트의 끝으로 이동
            for i in range(0, k-1):
                num_list.append(num_list.pop(0))
            
            # k번째 사람(현재 리스트의 첫 번째 사람)을 제거
            num_list.pop(0)
            cnt -= 1  # 남은 사람 수 감소
        
        # 마지막으로 남은 사람이 승자
        return num_list[0]

solution = Solution()
result = solution.findTheWinner(5, 3)
print(result)  # 출력: 4
