from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        """
        이 함수는 문자열 배열에서 가장 긴 공통 접두사를 찾습니다.
        공통 접두사가 없으면 빈 문자열을 반환합니다.
        """
        
        if not strs:
            return ""  # 문자열 배열이 비어있으면 빈 문자열 반환
        
        # 모든 문자열의 최소 길이를 찾습니다.
        min_length = min(len(s) for s in strs)
        if min_length == 0:
            return ""  # 어떤 문자열이라도 빈 문자열이면 공통 접두사는 없음
        
        longest_prefix = ""  # 가장 긴 공통 접두사를 저장할 변수
        
        # 첫 번째 문자열의 각 문자 위치를 기준으로 공통 접두사를 찾습니다.
        for i in range(min_length):
            # 현재 위치의 문자 가져오기 (첫 번째 문자열 기준)
            current_char = strs[0][i]
            
            # 모든 문자열이 현재 위치에서 같은 문자를 가지고 있는지 확인
            for string in strs[1:]:
                if string[i] != current_char:
                    return longest_prefix  # 다른 문자가 발견되면 현재까지의 접두사 반환
            
            # 모든 문자열이 현재 문자를 공유하면 접두사에 추가
            longest_prefix += current_char
        
        return longest_prefix  # 모든 문자가 공통 접두사인 경우 전체 접두사 반환
