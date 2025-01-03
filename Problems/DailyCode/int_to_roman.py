class Solution:
    def intToRoman(self, num: int) -> str:
        """
        이 함수는 주어진 정수를 로마 숫자로 변환하여 반환합니다.
        로마 숫자는 다음과 같은 7개의 기호를 사용합니다:
        
        Symbol	Value
        I	1
        V	5
        X	10
        L	50
        C	100
        D	500
        M	1000
        
        변환 규칙:
        1. 가장 큰 값부터 가능한 많이 빼면서 로마 숫자를 만듭니다.
        2. 4, 9, 40, 90, 400, 900과 같은 경우에는 빼는 기호를 사용한 특별한 표기를 사용합니다.
        3. 동일한 기호는 최대 3번까지 연속해서 사용할 수 있습니다.
        
        예:
        - 3 -> "III"
        - 4 -> "IV"
        - 9 -> "IX"
        - 58 -> "LVIII" (50 + 5 + 3)
        - 1994 -> "MCMXCIV" (1000 + (1000-100) + (100-10) + (5-1))
        
        Parameters:
        - num (int): 변환할 정수 (1 <= num <= 3999)
        
        Returns:
        - str: 주어진 정수를 로마 숫자로 변환한 문자열
        """
        
        # 로마 숫자와 그에 해당하는 정수 값을 매칭한 리스트를 정의합니다.
        # 내림차순으로 정렬하여 가장 큰 값부터 처리할 수 있도록 합니다.
        value_symbols = [
            (1000, 'M'),  # 1000 -> M
            (900, 'CM'),  # 900 -> CM
            (500, 'D'),   # 500 -> D
            (400, 'CD'),  # 400 -> CD
            (100, 'C'),   # 100 -> C
            (90, 'XC'),   # 90 -> XC
            (50, 'L'),    # 50 -> L
            (40, 'XL'),   # 40 -> XL
            (10, 'X'),    # 10 -> X
            (9, 'IX'),    # 9 -> IX
            (5, 'V'),     # 5 -> V
            (4, 'IV'),    # 4 -> IV
            (1, 'I')      # 1 -> I
        ]
        
        roman = ""  # 결과 로마 숫자를 저장할 문자열을 초기화합니다.
        
        # 정의된 값-기호 쌍을 순회하면서 로마 숫자를 구성합니다.
        for value, symbol in value_symbols:
            if num == 0:
                break  # 모든 숫자를 변환했다면 반복을 종료합니다.
            
            # 현재 값으로 나눌 수 있는 횟수를 계산합니다.
            count = num // value
            if count != 0:
                # 현재 기호를 필요한 만큼 결과 문자열에 추가합니다.
                roman += symbol * count
                # 변환한 값을 전체 숫자에서 뺍니다.
                num -= value * count
        
        return roman  # 완성된 로마 숫자 문자열을 반환합니다.

# 테스트를 위한 예제 사용
if __name__ == "__main__":
    solution = Solution()
    
    # 예제 1
    num1 = 3749
    print(f"Input: {num1}")
    print(f"Output: {solution.intToRoman(num1)}")  # 예상 출력: "MMMDCCXLIX"
    
    # 예제 2
    num2 = 58
    print(f"Input: {num2}")
    print(f"Output: {solution.intToRoman(num2)}")  # 예상 출력: "LVIII"
    
    # 예제 3
    num3 = 1994
    print(f"Input: {num3}")
    print(f"Output: {solution.intToRoman(num3)}")  # 예상 출력: "MCMXCIV"
    
    # 추가 테스트 케이스
    num4 = 4
    print(f"Input: {num4}")
    print(f"Output: {solution.intToRoman(num4)}")  # 예상 출력: "IV"
    
    num5 = 9
    print(f"Input: {num5}")
    print(f"Output: {solution.intToRoman(num5)}")  # 예상 출력: "IX"
    
    num6 = 58
    print(f"Input: {num6}")
    print(f"Output: {solution.intToRoman(num6)}")  # 예상 출력: "LVIII"
    
    num7 = 3
    print(f"Input: {num7}")
    print(f"Output: {solution.intToRoman(num7)}")  # 예상 출력: "III"
