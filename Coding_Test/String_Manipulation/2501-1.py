def is_palindromic(s: str) -> bool:
    """
    문자열 s가 팰린드롬인지(앞뒤가 같은지) 확인하여,
    팰린드롬이면 True, 아니면 False를 반환합니다.
    """
    return s == s[::-1]

def LPS(s: str) -> tuple:
    """
    문자열 s의 가장 긴 팰린드롬 부분수열(Longest Palindromic Subsequence)의 
    (길이, 부분수열)을 반환합니다.
    
    - 여러 LPS가 존재할 경우 사전순으로 가장 작은 팰린드롬을 반환합니다.
    """
    n = len(s)
    # dp[i][j] = (L, P)
    #   L: s[i..j] 범위에서 LPS(가장 긴 팰린드롬 부분수열)의 길이
    #   P: 가장 긴 팰린드롬 부분수열 중 사전순으로 가장 앞선 문자열
    dp = [[(0, "") for _ in range(n)] for _ in range(n)]
    
    # 부분 문자열의 길이가 1인 경우 (기저 사례)
    for i in range(n):
        dp[i][i] = (1, s[i])
    
    # 부분 문자열의 길이를 2 이상으로 늘려가며 DP 채우기
    for length in range(2, n+1):  # length: 부분 문자열의 길이
        for i in range(n - length + 1):
            j = i + length - 1  # 부분 문자열 s[i..j]
            
            # 양 끝 문자가 같은 경우
            if s[i] == s[j]:
                # 안쪽 부분이 존재한다면
                if i+1 <= j-1:
                    inner_len, inner_pal = dp[i+1][j-1]
                    dp[i][j] = (inner_len + 2, s[i] + inner_pal + s[j])
                else:
                    # 예: "aa", "aba"와 같이 가운데가 비거나 한 글자뿐인 경우
                    # s[i..j] 자체가 2글자 이상이면서 양 끝이 같으니, 길이는 2 또는 3
                    dp[i][j] = (j - i + 1, s[i:j+1])
            
            else:
                # 양 끝 문자가 다를 경우
                left_len,  left_pal  = dp[i+1][j]
                right_len, right_pal = dp[i][j-1]
                
                # 더 긴 길이를 우선
                if left_len > right_len:
                    dp[i][j] = (left_len, left_pal)
                elif right_len > left_len:
                    dp[i][j] = (right_len, right_pal)
                else:
                    # 길이가 같으면 사전순 비교
                    if left_pal < right_pal:
                        dp[i][j] = (left_len, left_pal)
                    else:
                        dp[i][j] = (right_len, right_pal)
    
    # 전체 문자열 s[0..n-1]의 LPS 결과
    return dp[0][n-1]

# 1) is_palindromic 테스트
print(is_palindromic("bbbab"))  # 팰린드롬인지? False
print(is_palindromic("ete"))    # 팰린드롬인지? True

# 2) LPS 테스트
print(LPS("mnbvcxz"))  
# 해당 문자열은 반복되는 문자가 없으므로
# LPS의 길이는 1, 그 중 사전순으로 가장 작은 글자를 반환해야 합니다.
# "m", "n", "b", "v", "c", "x", "z" 중 ASCII 코드는 b가 가장 작습니다.
# 결과 예: (1, 'b')
