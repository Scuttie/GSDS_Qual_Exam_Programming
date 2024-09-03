class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        # 특정 순서쌍을 제거하고 점수를 계산하는 함수
        def remove_substring(s, first, first_points):
            stack = []  # 스택을 사용하여 문자열 처리
            score = 0   # 점수 초기화
            for char in s:
                stack.append(char)
                # 스택의 마지막 두 문자가 제거할 순서쌍과 일치하는지 확인
                if len(stack) >= 2 and ''.join(stack[-2:]) == first:
                    score += first_points  # 점수 추가
                    stack.pop()  # 순서쌍 제거
                    stack.pop()
            return ''.join(stack), score  # 남은 문자열과 얻은 점수 반환
        
        # x와 y의 크기를 비교하여 더 높은 점수를 주는 순서쌍을 먼저 제거
        if x >= y:
            first, first_points = "ab", x
            second, second_points = "ba", y
        else:
            first, first_points = "ba", y
            second, second_points = "ab", x
        
        # 첫 번째 순서쌍 제거 후 점수 계산
        s, score1 = remove_substring(s, first, first_points)
        
        # 두 번째 순서쌍 제거 후 점수 계산
        _, score2 = remove_substring(s, second, second_points)
        
        # 두 단계에서 얻은 점수의 합을 반환
        return score1 + score2

s = "aabbaaxybbaabb"
x = 5
y = 4

solution = Solution()
result = solution.maximumGain(s, x, y)
print(result)  # 출력: 19
