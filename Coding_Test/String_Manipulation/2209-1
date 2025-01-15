def str_perm(s: str) -> list:
    """
    문자열 s(소문자 알파벳으로만 구성)에 대해,
    - 모든 순열을 찾아
    - 중복 없이
    - 사전순으로 정렬된 리스트를 반환한다.

    예:
      str_perm("abc") -> ["abc", "acb", "bac", "bca", "cab", "cba"]
      str_perm("abb") -> ["abb", "bab", "bba"]
    """

    # 1. 문자열을 정렬하여 문자 배열을 얻는다 (사전순 관리를 위해)
    chars = sorted(s)
    n = len(chars)

    # 2. 백트래킹 준비
    used = [False] * n  # 각 문자 사용 여부
    result = []
    current = []

    def backtrack():
        # 모든 자리를 채웠다면 결과에 추가
        if len(current) == n:
            result.append("".join(current))
            return

        for i in range(n):
            # 이미 사용한 문자라면 패스
            if used[i]:
                continue
            # 직전에 같은 문자가 있었고, 그 문자를 아직 사용 안 했다면 (중복 순열 방지)
            if i > 0 and chars[i] == chars[i - 1] and not used[i - 1]:
                continue

            # i번째 문자 사용
            used[i] = True
            current.append(chars[i])

            backtrack()

            # 사용했던 것 되돌리기
            current.pop()
            used[i] = False

    # 3. 백트래킹 시작
    backtrack()
    return result

if __name__ == "__main__":
    print(str_perm("abc"))
    # ["abc", "acb", "bac", "bca", "cab", "cba"]

    print(str_perm("abb"))
    # ["abb", "bab", "bba"]
