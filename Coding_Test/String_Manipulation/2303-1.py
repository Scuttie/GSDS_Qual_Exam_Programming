def foo(s: str) -> str:
    """
    문자열 s를 재배열하여,
    1) s에서 인접했던 두 문자가 t에서도 인접하지 않도록
    2) s의 문자를 동일한 빈도로 모두 사용
    하는 문자열 t를 찾아서 반환.
    불가능하면 "" 반환.
    """
    n = len(s)
    if n <= 1:
        # 길이가 0이나 1이면 그 자체로 이미 조건을 만족.
        return s

    # 1) s에서 "금지된 쌍" 집합 만들기 (방향 무관)
    forbidden = set()
    for i in range(n - 1):
        a, b = s[i], s[i+1]
        # (a,b), (b,a) 금지 → 정렬하여 저장
        pair = (min(a, b), max(a, b))
        forbidden.add(pair)

    # 2) s의 모든 순열을 검사하기 위해, 문자들을 리스트로 꺼냄
    chars = list(s)
    
    # 백트래킹을 위한 방문 여부
    used = [False] * n
    candidate = []

    def backtrack():
        # 모든 자리를 채운 경우 검사
        if len(candidate) == n:
            # candidate가 유효한지 검사
            for i in range(n - 1):
                x, y = candidate[i], candidate[i+1]
                if (min(x, y), max(x, y)) in forbidden:
                    return False  # 유효 X
            return True  # 끝까지 문제 없으면 유효

        # 자리 채워넣기
        for idx in range(n):
            if used[idx]:
                continue
            candidate.append(chars[idx])
            used[idx] = True
            if backtrack():
                return True
            # 되돌리기
            candidate.pop()
            used[idx] = False
        return False

    # 백트래킹 시작
    if backtrack():
        return "".join(candidate)
    else:
        return ""


def bar(s: str) -> str:
    """
    foo(s)와 동일 조건 + 결과 t가 s와 달라야 함.
    불가능하면 "".
    """
    n = len(s)
    if n <= 1:
        # 길이가 0이나 1인 경우, s와 다른 문자열을 만들기 자체가 불가능.
        # 게다가 길이 1이면 인접문자 문제는 자동으로 만족이지만,
        # "s와 달라야 한다" → 동일한 한 글자 말고는 대안이 없으므로 "".
        return ""

    # 1) s에서 금지된 쌍 집합
    forbidden = set()
    for i in range(n - 1):
        a, b = s[i], s[i+1]
        pair = (min(a, b), max(a, b))
        forbidden.add(pair)

    chars = list(s)
    used = [False] * n
    candidate = []

    def backtrack():
        if len(candidate) == n:
            # 후보 문자열 완성되면 유효성 검사 + s와 다른지 확인
            t = "".join(candidate)
            if t == s:
                return False  # s와 다르지 않으면 패스
            # 인접 금지 검사
            for i in range(n - 1):
                x, y = candidate[i], candidate[i+1]
                if (min(x, y), max(x, y)) in forbidden:
                    return False
            return True

        for idx in range(n):
            if used[idx]:
                continue
            candidate.append(chars[idx])
            used[idx] = True
            if backtrack():
                return True
            candidate.pop()
            used[idx] = False
        return False

    if backtrack():
        return "".join(candidate)
    else:
        return ""


# ------------------------------
# 간단 테스트
if __name__ == "__main__":
    print(foo("abcde"))  # 예: "adbec" 등
    print(foo("abc"))    # 예: "" (불가능)
    print(foo(""))       # 예: "" (그대로)

    print(bar("abcde"))  # 예: "adbec" 등 (단, "abcde" 그대로면 안 됨)
    print(bar("abc"))    # 예: "" (불가능)
    print(bar(""))       # 예: "" (원본과 다른 문자열 자체를 만들 수 X)
