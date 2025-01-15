class Node:
    def __init__(self, data, nxt=None):
        self.data = data
        self.next = nxt

def print_list(s: Node) -> None:
    print("[", end="")
    first = True
    cur = s
    while cur:
        if not first:
            print(", ", end="")
        print(cur.data, end="")
        first = False
        cur = cur.next
    print("]")

def reverse_list(head: Node) -> Node:
    prev = None
    cur = head
    while cur:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    return prev

def palindrome(head: Node) -> int:
    if head is None or head.next is None:
        return 1
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    rev = reverse_list(slow)
    p1 = head
    p2 = rev
    is_pal = True
    while p2:
        if p1.data != p2.data:
            is_pal = False
            break
        p1 = p1.next
        p2 = p2.next
    # 원상 복구
    reverse_list(rev)
    return 1 if is_pal else 0

def sub_list(s: Node, t: Node) -> int:
    if t is None:
        # 문제 요구사항에 따라 다를 수 있지만, 여기서는 "빈 리스트도 부분 리스트"라 가정하고 1 반환 가능
        return 1

    start = s
    while start:
        p_s = start
        p_t = t
        while p_s and p_t and (p_s.data == p_t.data):
            p_s = p_s.next
            p_t = p_t.next
        if p_t is None:  
            # t를 전부 매칭시켰다면 성공
            return 1
        start = start.next
    return 0

def length(head: Node) -> int:
    cnt = 0
    cur = head
    while cur:
        cnt += 1
        cur = cur.next
    return cnt

def get_data_at(head: Node, index: int) -> int:
    cur = head
    i = 0
    while cur and i < index:
        cur = cur.next
        i += 1
    return cur.data

def palindrome_sub(head: Node, start: int, end: int) -> int:
    left_i = start
    right_i = end
    while left_i < right_i:
        left_val = get_data_at(head, left_i)
        right_val = get_data_at(head, right_i)
        if left_val != right_val:
            return 0
        left_i += 1
        right_i -= 1
    return 1

def print_sublist(head: Node, start: int, end: int) -> None:
    print("[", end="")
    idx = start
    while idx <= end:
        val = get_data_at(head, idx)
        print(val, end="")
        if idx < end:
            print(",", end="")
        idx += 1
    print("]", end="")

def max_palindromes(s: Node) -> None:
    n = length(s)
    if n == 0:
        print("[]")
        return
    # 모든 팰린드롬 구간 찾기
    pal_ranges = []
    for i in range(n):
        for j in range(i, n):
            if palindrome_sub(s, i, j) == 1:
                pal_ranges.append((i, j))
    # 더 큰 팰린드롬에 '포함'되는 것 제외
    maximal = []
    for (i, j) in pal_ranges:
        contained = False
        for (p, q) in pal_ranges:
            if (p <= i and j <= q) and (p < i or j < q):
                contained = True
                break
        if not contained:
            maximal.append((i, j))
    # 시작 인덱스 기준 정렬
    maximal.sort(key=lambda x: x[0])
    # 출력
    print("[", end="")
    first = True
    for (i, j) in maximal:
        if not first:
            print(", ", end="")
        print_sublist(s, i, j)
        first = False
    print("]")

# -------------------------------------------------------------------------
# 연결 리스트를 만드는데 편리한 헬퍼 함수 (테스트 시 사용)
def build_list(arr) -> Node:
    """
    파이썬 리스트 arr의 원소들을 사용해 연결 리스트를 만들어 반환.
    """
    if not arr:
        return None
    head = Node(arr[0])
    cur = head
    for x in arr[1:]:
        cur.next = Node(x)
        cur = cur.next
    return head

# 메인 (테스트용)
if __name__ == "__main__":

    # 1) 간단한 예시
    s1 = build_list([3, 7, 6, 8])
    print("s1 =", end=" ")
    print_list(s1)  # [3, 7, 6, 8]
    print("palindrome(s1) =", palindrome(s1))  # 0

    # 2) 팰린드롬 예시
    s2 = build_list([1, 2, 3, 2, 1])
    print("s2 =", end=" ")
    print_list(s2)  # [1, 2, 3, 2, 1]
    print("palindrome(s2) =", palindrome(s2))  # 1 (팰린드롬)

    # 3) 부분 리스트(sub_list) 테스트
    # s1: [3, 7, 6, 8] / t: [7, 6]
    t = build_list([7, 6])
    print("t =", end=" ")
    print_list(t)    # [7, 6]
    print("sub_list(s1, t) =", sub_list(s1, t))  # 1 (연속된 부분 리스트)

    # 4) sub_list가 아닐 경우
    t2 = build_list([6, 7])
    print("t2 =", end=" ")
    print_list(t2)    # [6, 7]
    print("sub_list(s1, t2) =", sub_list(s1, t2))  # 0 (순서 안 맞음)

    # 5) max_palindromes 테스트
    # 예: s3 = [8,1,2,3,3,2,1,4,9,4]
    # 문제 예시보다 짧게 해서 확인
    s3 = build_list([8, 1, 2, 3, 3, 2, 1, 4, 9, 4])
    print("s3 =", end=" ")
    print_list(s3)
    print("palindrome(s3) =", palindrome(s3))  # 아마 0
    print("max_palindromes(s3) =", end=" ")
    max_palindromes(s3)  
    # 결과 예 (출력 형식 다양 가능):
    # 예) [[8],[1,2,3,3,2,1],[4,9,4]]  (등등)
