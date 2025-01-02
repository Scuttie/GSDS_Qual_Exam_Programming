"""
문제 설명:

배열 A는 N개의 정수로 구성되어 있으며, 이는 N일 연속 기간 동안의 주식 가격을 나타냅니다.
배열 A의 각 요소 A[I]는 I번째 날의 주식 가격을 의미합니다.

만약 한 주식을 P일에 매수하고 Q일에 매도한다고 할 때, 여기서 0 ≤ P ≤ Q < N이라면,
이 거래의 이익은 A[Q] − A[P]입니다. 단, A[Q] ≥ A[P]인 경우에만 이익이 발생하며,
그렇지 않으면 손실이 발생하여 A[P] − A[Q]만큼의 손실이 발생합니다.

예를 들어, 다음과 같은 배열 A가 주어졌을 때:
  A[0] = 23171
  A[1] = 21011
  A[2] = 21123
  A[3] = 21366
  A[4] = 21013
  A[5] = 21367

- 0일에 매수하고 2일에 매도하면, 이익은 A[2] - A[0] = 21123 - 23171 = -2048 (손실)
- 4일에 매수하고 5일에 매도하면, 이익은 A[5] - A[4] = 21367 - 21013 = 354
- 가장 큰 이익은 1일에 매수하고 5일에 매도하여 356의 이익을 얻습니다.

목표는 배열 A에서 단 한 번의 거래로 얻을 수 있는 최대 이익을 찾는 것입니다.
만약 어떤 거래도 이익을 낼 수 없다면 0을 반환해야 합니다.

함수 정의:

def solution(A)

- A: 주식 가격을 나타내는 정수 배열
- 반환값: 단 한 번의 거래로 얻을 수 있는 최대 이익 (이익을 낼 수 없으면 0)

제약 조건:

- N은 0 이상 400,000 이하의 정수입니다.
- 각 요소 A[i]는 0 이상 200,000 이하의 정수입니다.

해결 방법:

배열을 한 번 순회하면서 현재까지의 최소 주식 가격을 추적합니다.
각 날마다 현재 주식 가격에서 최소 주식 가격을 빼서 가능한 최대 이익을 계산하고,
그 중 가장 큰 값을 반환합니다.
이 접근 방식은 시간 복잡도 O(N)으로 매우 효율적입니다.
"""

def solution(A):
    """
    주어진 주식 가격 배열 A에서 단 한 번의 거래로 얻을 수 있는 최대 이익을 반환합니다.
    만약 어떤 거래도 이익을 낼 수 없다면 0을 반환합니다.
    
    :param A: 리스트[int] - 주식 가격을 나타내는 정수 배열
    :return: int - 최대 이익 또는 0
    """
    if not A:
        # 주식 가격 배열이 비어있으면 이익을 낼 수 없으므로 0 반환
        return 0
    
    min_price = A[0]  # 현재까지의 최소 주식 가격을 첫 번째 요소로 초기화
    max_profit = 0     # 최대 이익을 0으로 초기화
    
    for i in range(1, len(A)):
        current_price = A[i]
        # 현재 주식 가격에서 현재까지의 최소 주식 가격을 빼서 이익 계산
        potential_profit = current_price - min_price
        
        if potential_profit > max_profit:
            # 계산된 이익이 현재 최대 이익보다 크면 최대 이익 업데이트
            max_profit = potential_profit
        
        if current_price < min_price:
            # 현재 주식 가격이 현재까지의 최소 주식 가격보다 작으면 최소 주식 가격 업데이트
            min_price = current_price
    
    return max_profit if max_profit > 0 else 0  # 이익이 있으면 반환, 없으면 0 반환

# 테스트를 위한 메인 함수
def main():
    # 테스트 케이스 목록
    test_cases = [
        {
            'A': [23171, 21011, 21123, 21366, 21013, 21367],
            'expected': 356
        },
        {
            'A': [1, 2, 3, 4, 5],
            'expected': 4
        },
        {
            'A': [5, 4, 3, 2, 1],
            'expected': 0
        },
        {
            'A': [7, 1, 5, 3, 6, 4],
            'expected': 5
        },
        {
            'A': [],
            'expected': 0
        },
        {
            'A': [1],
            'expected': 0
        },
        {
            'A': [2, 1, 2, 1, 0, 1, 2],
            'expected': 2
        },
        {
            'A': [3, 3, 5, 0, 0, 3, 1, 4],
            'expected': 4
        },
        {
            'A': [1, 3, 5],
            'expected': 4
        },
        {
            'A': [2, 2, 2, 0, 1],
            'expected': 1
        },
    ]
    
    # 각 테스트 케이스에 대해 결과를 검증
    for idx, test in enumerate(test_cases, 1):
        A = test['A']
        expected = test['expected']
        result = solution(A)
        print(f"테스트 케이스 {idx}:")
        print(f"입력: {A}")
        print(f"예상 출력: {expected}")
        print(f"실제 출력: {result}")
        print("PASS" if result == expected else "FAIL")
        print("-" * 50)

if __name__ == "__main__":
    main()
