class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        full_bottle = numBottles  # 현재 가지고 있는 가득 찬 물병의 수
        empty_bottle = 0  # 현재 가지고 있는 빈 물병의 수
        sum = numBottles  # 총 마신 물병의 수, 초기값은 처음 받은 물병 수
        
        # 가득 찬 물병과 빈 병의 합이 교환 조건 이상일 때까지 반복
        while (full_bottle + empty_bottle >= numExchange):
            empty_bottle += full_bottle  # 모든 가득 찬 물병을 다 마시고 빈 병으로 전환
            full_bottle = empty_bottle // numExchange  # 빈 병을 새 물병으로 교환
            empty_bottle = empty_bottle % numExchange  # 교환 후 남은 빈 병의 수
            sum += full_bottle  # 교환으로 얻은 새 물병의 수를 총합에 추가
        
        # 총 마신 물병의 수 반환
        return sum

# 예제 입력
numBottles = 9
numExchange = 3

# 솔루션 인스턴스 생성
solution = Solution()

# 결과 계산
result = solution.numWaterBottles(numBottles, numExchange)

# 출력: 13
print(result)
