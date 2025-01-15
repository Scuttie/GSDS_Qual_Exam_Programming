############################################
# (a) palindrome(s)
############################################
def palindrome(s: str) -> int:
    """
    문자열 s가 앞뒤가 같은 팰린드롬이면 1, 아니면 0을 반환.
    (소문자 알파벳, 공백 문자 포함 가능)
    """
    n = my_len(s)
    # 양 끝에서부터 비교
    left = 0
    right = n - 1
    while left < right:
        if char_at(s, left) != char_at(s, right):
            return 0
        left += 1
        right -= 1
    return 1

############################################
# (b) substring(s, t)
############################################
def substring(s: str, t: str) -> int:
    """
    문자열 t가 s의 '연속된 부분 문자열'로 존재하면 1, 아니면 0.
    (빌트인 "in" 연산자 등을 쓰지 않고 직접 구현)
    """
    n_s = my_len(s)
    n_t = my_len(t)

    # 빈 문자열 t에 대한 정의는 문제에 따라 달라질 수 있으나,
    # 보통 "빈 문자열은 어디에나 부분 문자열로 간주"할 수도 있음.
    # 여기서는 n_t == 0 이면 1로 처리해 줍니다.
    if n_t == 0:
        return 1

    # i 위치부터 t가 일치하는지 확인
    for i in range(n_s - n_t + 1):
        match = 1
        for j in range(n_t):
            if char_at(s, i + j) != char_at(t, j):
                match = 0
                break
        if match == 1:
            return 1
    return 0

############################################
# (c) max_palindromes(s)
############################################
def max_palindromes(s: str) -> list:
    """
    문자열 s에서 얻을 수 있는 '팰린드롬 부분 문자열'들 중
     - 다른 더 큰 팰린드롬의 부분 문자열이 되어버리지 않는
       (즉, 포함되지 않는) '최대' 팰린드롬들을 찾아
    리스트로 반환한다.

    예) s = "kabccbadzdefgfeda"
        -> ["k", "abccba", "dzd", "defgfed"] (문제 예시)

    구현 방법 개요:
      1) 모든 부분 구간 s[i..j]를 찾아 팰린드롬인지 확인.
      2) 팰린드롬이면 (i, j) 쌍을 pal_ranges에 저장.
      3) 더 큰 (p, q) 팰린드롬에 완전히 포함된 (i, j)는 제외.
      4) 남은 것들을 문자열 형태로 변환해서 리스트로 반환.
    """
    n = my_len(s)
    pal_ranges = []

    # 1) 모든 (i, j)에 대해 팰린드롬 검사
    for i in range(n):
        for j in range(i, n):
            if palindrome_sub(s, i, j) == 1:
                pal_ranges.append((i, j))

    # 2) '더 큰 팰린드롬'에 포함되면 제외
    #    (p <= i <= j <= q) 이고 (p,q) != (i,j) 이면 (i,j)는 더 큰 (p,q)에 포함
    maximal = []
    for (i, j) in pal_ranges:
        is_contained = 0
        for (p, q) in pal_ranges:
            if (p <= i and j <= q) and not (p == i and q == j):
                # (i,j)가 (p,q)에 '진짜로' 포함되면
                is_contained = 1
                break
        if is_contained == 0:
            maximal.append((i, j))

    # 3) 문제 예시에 맞춰 '등장 순'(i가 작은 순)으로 정렬
    maximal.sort(key=lambda x: x[0])

    # 4) 최종 결과를 문자열 형태로 변환
    result = []
    for (start, end) in maximal:
        result.append(get_substring(s, start, end))

    return result

############################################
# 아래는 위 함수들을 지원하기 위한 보조함수들
# (문제에서 "빌트인 함수를 쓰지 말라" 했을 때
#  주로 len(), s[i:j] 슬라이싱 등 직접 구현 예시입니다.)
############################################

def my_len(s: str) -> int:
    """문자열 길이를 내장 len 함수 없이 구하기"""
    cnt = 0
    for _ in s:  # 파이썬의 기본 반복은 결국 내부적으로 이터레이터를 쓰지만,
                 # 문제 요구사항에 따라 '직접' 세는 것으로 간주 가능
        cnt += 1
    return cnt

def char_at(s: str, index: int) -> str:
    """문자열 s의 index번째 문자를 반환 (s[index] 대신)"""
    # 0 <= index < len(s) 라고 가정
    # 그냥 for로 세면서 찾음
    i = 0
    for ch in s:
        if i == index:
            return ch
        i += 1
    # 정상 상황이라면 여기 오지 않음
    return ""  # 혹은 raise IndexError 등을 할 수도 있음

def get_substring(s: str, start: int, end: int) -> str:
    """
    s의 start~end(포함) 구간을 잘라 반환.
    (슬라이싱 s[start:end+1] 대신, 인덱스 반복)
    """
    buf = []
    i = start
    while i <= end:
        buf.append(char_at(s, i))
        i += 1
    # join 없이 직접 이어붙일 수도 있지만,
    # 문제에서 'join'도 built-in인지 엄격히 따진다면
    # 직접 루프 돌며 추가해도 됨.
    return list_to_string(buf)

def list_to_string(char_list: list) -> str:
    """문자 리스트를 문자열로 합치기 (''.join 대체 예시)"""
    result = ""
    for c in char_list:
        result += c  # 문자열 이어붙이기 (비효율적이지만 문제 취지상 가능)
    return result

def palindrome_sub(s: str, start: int, end: int) -> int:
    """
    s의 부분 구간 s[start..end]가 팰린드롬인지 1/0 반환
    (문자열 슬라이싱 대신 직접 확인)
    """
    while start < end:
        if char_at(s, start) != char_at(s, end):
            return 0
        start += 1
        end -= 1
    return 1

# 예) 문제 예시 1
s1 = "kabccbadzdefgfeda"
print(max_palindromes(s1))
# -> ["k", "abccba", "dzd", "defgfed"] (예시)

# 예) 문제 예시 2
s2 = "kabccba dzabccbaza"
print(max_palindromes(s2))
# -> ["k", " ", "d", "zabccbaz", "aza"] (예시)

# 별도로 palindrome(s), substring(s, t)를 테스트해볼 수도 있음
print(palindrome("racecar"))    # 1
print(palindrome("apple"))      # 0

print(substring("abc def", "c d"))  # 1
print(substring("abc def", "cd"))   # 0
