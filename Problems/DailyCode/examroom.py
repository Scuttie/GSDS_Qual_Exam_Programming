"""
문제 설명:

ExamRoom 클래스는 시험실의 좌석 배치를 시뮬레이션합니다. 시험실에는 0부터 n-1까지 번호가 매겨진 n개의 좌석이 일렬로 배열되어 있습니다.

게임 규칙은 다음과 같습니다:

1. 학생이 시험실에 들어오면, 그들은 가장 가까운 사람과의 거리를 최대화하는 좌석에 앉아야 합니다. 만약 그러한 좌석이 여러 개라면, 가장 낮은 번호의 좌석에 앉습니다.
2. 만약 아무도 시험실에 앉아 있지 않다면, 학생은 좌석 번호 0에 앉습니다.
3. 학생이 좌석을 떠날 때는, 해당 좌석에서 학생이 제거됩니다. 이때, 해당 좌석에는 반드시 학생이 앉아있어야 합니다.

ExamRoom 클래스는 다음과 같은 메서드를 포함합니다:

- `ExamRoom(int n)`: 좌석의 개수 n으로 ExamRoom 객체를 초기화합니다.
- `int seat()`: 다음 학생이 앉을 좌석의 번호를 반환합니다.
- `void leave(int p)`: 좌석 번호 p에서 학생이 떠났음을 표시합니다.

제약 조건:

- 1 <= n <= 10^9
- 좌석 번호 p는 항상 학생이 앉아있는 좌석이어야 합니다.
- `seat`와 `leave` 메서드는 최대 10^4번 호출됩니다.

해결 방법:

시험실의 좌석이 매우 많을 수 있으므로(최대 10^9), 효율적인 자료구조를 사용하여 학생들이 앉은 좌석을 관리해야 합니다. Python에서는 `bisect` 모듈을 사용하여 정렬된 리스트에 대한 이진 탐색을 효율적으로 수행할 수 있습니다.

1. **학생이 앉은 좌석 관리**: 학생이 앉은 좌석을 정렬된 리스트(occupied)로 관리합니다.
2. **좌석 선택 (`seat` 메서드)**:
    - 만약 아무도 앉아있지 않다면, 좌석 0에 앉습니다.
    - 그렇지 않다면, 각 구간에서 가장 먼 좌석을 찾아 그 중 최소 번호의 좌석을 선택합니다.
    - 구간의 첫 부분과 마지막 부분도 고려하여 최대 거리를 계산합니다.
3. **좌석 떠남 (`leave` 메서드)**:
    - 학생이 떠난 좌석을 정렬된 리스트에서 제거합니다.

이 접근 방식은 각 `seat` 및 `leave` 연산을 O(log n) 시간에 수행할 수 있어, 주어진 제약 조건 내에서 효율적으로 동작합니다.
"""

import bisect
from typing import List

class ExamRoom:
    def __init__(self, n: int):
        """
        ExamRoom 클래스를 초기화합니다.
        
        :param n: 좌석의 총 개수
        """
        self.n = n
        self.occupied = []  # 학생이 앉은 좌석을 저장하는 정렬된 리스트

    def seat(self) -> int:
        """
        다음 학생이 앉을 좌석 번호를 반환합니다.
        가장 가까운 학생과의 거리를 최대화하는 좌석을 선택하며, 여러 후보가 있을 경우 가장 낮은 번호의 좌석을 선택합니다.
        
        :return: 학생이 앉을 좌석 번호
        """
        if not self.occupied:
            # 아무도 앉아있지 않다면, 좌석 0에 앉습니다.
            bisect.insort(self.occupied, 0)
            return 0

        max_dist = self.occupied[0]  # 첫 좌석과 좌석 0 사이의 거리
        seat = 0  # 선택된 좌석 번호

        # 좌석 사이의 최대 거리를 찾습니다.
        for i in range(1, len(self.occupied)):
            prev = self.occupied[i - 1]
            curr = self.occupied[i]
            dist = (curr - prev) // 2  # 가운데 좌석을 선택하여 거리를 최대화
            if dist > max_dist:
                max_dist = dist
                seat = prev + dist

        # 마지막 좌석과 n-1 좌석 사이의 거리를 확인합니다.
        last_dist = self.n - 1 - self.occupied[-1]
        if last_dist > max_dist:
            seat = self.n - 1

        # 선택된 좌석을 occupied 리스트에 삽입합니다.
        bisect.insort(self.occupied, seat)
        return seat

    def leave(self, p: int) -> None:
        """
        좌석 번호 p에서 학생이 떠났음을 표시합니다.
        
        :param p: 학생이 떠날 좌석 번호
        """
        # 학생이 앉아있는 좌석 리스트에서 p의 위치를 찾습니다.
        index = bisect.bisect_left(self.occupied, p)
        if index < len(self.occupied) and self.occupied[index] == p:
            self.occupied.pop(index)

# 테스트를 위한 헬퍼 함수
def run_test_case(test_num: int, n: int, operations: List[str], inputs: List[List[int]], expected: List[int]):
    """
    주어진 테스트 케이스를 실행하고 결과를 출력합니다.
    
    :param test_num: 테스트 케이스 번호
    :param n: ExamRoom 초기화 시의 좌석 개수
    :param operations: 수행할 연산 리스트 (["ExamRoom", "seat", "leave", ...])
    :param inputs: 각 연산에 대한 입력 리스트 ([[n], [p], ...])
    :param expected: 예상되는 출력 리스트 ([None, seat_num, None, ...])
    """
    exam_room = None
    actual = []
    for op, inp in zip(operations, inputs):
        if op == "ExamRoom":
            exam_room = ExamRoom(inp[0])
            actual.append(None)
        elif op == "seat":
            seat_num = exam_room.seat()
            actual.append(seat_num)
        elif op == "leave":
            exam_room.leave(inp[0])
            actual.append(None)
    # 결과 비교
    pass_flag = actual == expected
    # 결과 출력
    print(f"테스트 케이스 {test_num}:")
    print(f"연산: {operations}")
    print(f"입력: {inputs}")
    print(f"예상 출력: {expected}")
    print(f"실제 출력: {actual}")
    print("PASS" if pass_flag else "FAIL")
    print("-" * 50)

# 메인 함수: 솔루션 테스트
def main():
    test_cases = [
        {
            'test_num': 1,
            'n': 10,
            'operations': ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"],
            'inputs': [[10], [], [], [], [], [4], []],
            'expected': [None, 0, 9, 4, 2, None, 5]
        },
        {
            'test_num': 2,
            'n': 1,
            'operations': ["ExamRoom", "seat"],
            'inputs': [[1], []],
            'expected': [None, 0]
        },
        {
            'test_num': 3,
            'n': 2,
            'operations': ["ExamRoom", "seat", "leave", "seat"],
            'inputs': [[2], [], [0], []],
            'expected': [None, 0, None, 1]
        },
        {
            'test_num': 4,
            'n': 3,
            'operations': ["ExamRoom", "seat", "seat", "seat"],
            'inputs': [[3], [], [], []],
            'expected': [None, 0, 2, 1]
        },
        {
            'test_num': 5,
            'n': 4,
            'operations': ["ExamRoom", "seat", "seat", "leave", "seat"],
            'inputs': [[4], [], [], [0], []],
            'expected': [None, 0, 3, None, 1]
        },
        {
            'test_num': 6,
            'n': 5,
            'operations': ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"],
            'inputs': [[5], [], [], [], [], [3], []],
            'expected': [None, 0, 4, 2, 1, None, 3]
        },
        {
            'test_num': 7,
            'n': 6,
            'operations': ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat", "leave", "seat"],
            'inputs': [[6], [], [], [], [], [2], [], [4], []],
            'expected': [None, 0, 5, 2, 4, None, 3, None, 4]
        },
        {
            'test_num': 8,
            'n': 7,
            'operations': ["ExamRoom", "seat", "seat", "seat", "seat", "seat", "leave", "seat"],
            'inputs': [[7], [], [], [], [], [], [4], []],
            'expected': [None, 0, 6, 3, 2, 4, None, 5]
        },
        {
            'test_num': 9,
            'n': 8,
            'operations': ["ExamRoom", "seat", "seat", "seat", "leave", "seat", "leave", "seat"],
            'inputs': [[8], [], [], [], [3], [], [0], []],
            'expected': [None, 0, 7, 3, None, 4, None, 1]
        },
        {
            'test_num': 10,
            'n': 1000000000,
            'operations': ["ExamRoom", "seat", "seat", "seat", "leave", "seat", "seat", "leave", "seat", "seat"],
            'inputs': [[1000000000], [], [], [], [999999999], [], [], [0], [], []],
            'expected': [None, 0, 999999999, 500000000, None, 250000000, 750000000, None, 125000000, 875000000]
        },
    ]
    
    for test in test_cases:
        run_test_case(
            test['test_num'],
            test['n'],
            test['operations'],
            test['inputs'],
            test['expected']
        )

if __name__ == "__main__":
    main()
