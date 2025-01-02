# 프로그램 설명:
# 이 프로그램은 MyCalendarTwo 클래스를 구현하여 주어진 이벤트들을 예약하면서,
# 동시에 세 개 이상의 이벤트가 겹치지 않도록 관리합니다. 즉, 트리플 북킹(triple booking)을 방지합니다.
#
# 클래스 MyCalendarTwo는 다음과 같은 기능을 제공합니다:
# - MyCalendarTwo() : 캘린더 객체를 초기화합니다.
# - book(startTime, endTime) : 새로운 이벤트를 예약합니다.
#                             트리플 북킹이 발생하지 않으면 예약을 성공하고 True를 반환합니다.
#                             그렇지 않으면 예약을 거부하고 False를 반환합니다.

class MyCalendarTwo:
    def __init__(self):
        """
        MyCalendarTwo 클래스를 초기화합니다.
        - self.bookings: 현재까지 추가된 모든 이벤트를 저장하는 리스트.
        - self.overlaps: 현재까지 두 이벤트가 겹친 부분을 저장하는 리스트.
        """
        self.bookings = []   # 모든 예약을 저장
        self.overlaps = []   # 이중 예약(두 예약이 겹친 부분)을 저장

    def book(self, startTime: int, endTime: int) -> bool:
        """
        새로운 이벤트를 추가할 수 있는지 확인하고, 추가할 수 있다면 추가합니다.
        트리플 북킹이 발생하지 않으면 True를 반환하고, 그렇지 않으면 False를 반환합니다.

        :param startTime: 이벤트의 시작 시간
        :param endTime: 이벤트의 종료 시간
        :return: 이벤트를 추가할 수 있으면 True, 아니면 False
        """
        # 새로운 이벤트가 기존의 이중 예약(overlaps)과 겹치는지 확인
        for os, oe in self.overlaps:
            # 두 이벤트가 겹치는지 확인
            if not (endTime <= os or startTime >= oe):
                # 트리플 북킹이 발생하므로 예약 불가
                return False

        # 새로운 이벤트가 기존의 예약(bookings)과 겹치는 부분을 overlaps에 추가
        for bs, be in self.bookings:
            # 두 이벤트가 겹치는지 확인
            if not (endTime <= bs or startTime >= be):
                # 겹치는 부분을 계산하여 overlaps에 추가
                overlap_start = max(startTime, bs)
                overlap_end = min(endTime, be)
                self.overlaps.append((overlap_start, overlap_end))

        # 새로운 이벤트를 bookings에 추가
        self.bookings.append((startTime, endTime))

        # 트리플 북킹이 발생하지 않으므로 예약 성공
        return True

# 테스트를 위한 헬퍼 함수
def run_test_case(operations, inputs, expected):
    """
    주어진 연산과 입력을 바탕으로 MyCalendarTwo 클래스의 동작을 테스트합니다.

    :param operations: 수행할 연산들의 리스트 (예: ["MyCalendarTwo", "book", "book"])
    :param inputs: 각 연산에 대한 입력들의 리스트 (예: [[], [10, 20], [50, 60]])
    :param expected: 기대하는 출력들의 리스트 (예: [None, True, True])
    """
    my_calendar = None
    actual = []
    for op, inp in zip(operations, inputs):
        if op == "MyCalendarTwo":
            my_calendar = MyCalendarTwo()
            actual.append(None)  # 생성자는 반환값이 없으므로 None을 추가
        elif op == "book":
            start, end = inp
            result = my_calendar.book(start, end)
            actual.append(result)

    # 결과 비교
    pass_flag = actual == expected

    # 결과 출력
    print(f"Operations: {operations}")
    print(f"Inputs: {inputs}")
    print(f"Expected Output: {expected}")
    print(f"Actual Output:   {actual}")
    print("PASS" if pass_flag else "FAIL")
    print("-" * 50)

# 메인 함수: MyCalendarTwo 클래스 구현 및 테스트
def main():
    # 테스트 케이스 목록
    test_cases = [
        {
            'operations': ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"],
            'inputs': [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]],
            'expected': [None, True, True, True, False, True, True]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book"],
            'inputs': [[], [1, 10], [2, 7], [3, 19]],
            'expected': [None, True, True, True]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book", "book"],
            'inputs': [[], [10, 20], [15, 25], [20, 30], [5, 15]],
            'expected': [None, True, True, True, False]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book", "book", "book"],
            'inputs': [[], [0, 10], [10, 20], [20, 30], [5, 25], [25, 35]],
            'expected': [None, True, True, True, False, True]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book", "book", "book", "book", "book"],
            'inputs': [[], [1, 3], [2, 5], [4, 6], [5, 7], [6, 8], [3, 9]],
            'expected': [None, True, True, True, True, True, True]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book", "book"],
            'inputs': [[], [10, 20], [20, 30], [30, 40], [40, 50]],
            'expected': [None, True, True, True, True]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book", "book", "book", "book", "book", "book"],
            'inputs': [[], [5, 10], [5, 10], [5, 10], [5, 10], [5, 10], [5, 10], [5, 10]],
            'expected': [None, True, True, False, False, False, False, False]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book"],
            'inputs': [[], [1, 2], [2, 3], [3, 4]],
            'expected': [None, True, True, True]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book", "book", "book"],
            'inputs': [[], [10, 20], [15, 25], [20, 30], [25, 35], [30, 40]],
            'expected': [None, True, True, True, True, True]
        },
        {
            'operations': ["MyCalendarTwo", "book", "book", "book", "book", "book", "book", "book", "book"],
            'inputs': [[], [1, 5], [2, 6], [3, 7], [4, 8], [5, 9], [6, 10], [7, 11], [8, 12]],
            'expected': [None, True, True, True, True, True, True, True, True]
        },
    ]

    # 각 테스트 케이스에 대해 결과를 검증
    for idx, test in enumerate(test_cases, 1):
        operations = test['operations']
        inputs = test['inputs']
        expected = test['expected']
        run_test_case(operations, inputs, expected)

    # 추가 테스트 케이스 11:
    # ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
    # [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
    print("Additional Test Case 11:")
    operations = ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
    inputs = [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
    expected = [None, True, True, True, False, True, True]
    run_test_case(operations, inputs, expected)

    # 추가 테스트 케이스 12:
    # ["MyCalendarTwo", "book", "book", "book"]
    # [[], [0, 10], [0, 5], [5, 10]]
    print("Additional Test Case 12:")
    operations = ["MyCalendarTwo", "book", "book", "book"]
    inputs = [[], [0, 10], [0, 5], [5, 10]]
    expected = [None, True, True, True]
    run_test_case(operations, inputs, expected)

    # 추가 테스트 케이스 13:
    # ["MyCalendarTwo", "book", "book", "book", "book", "book"]
    # [[], [1, 10], [2, 7], [3, 19], [8, 12], [10, 20]]
    print("Additional Test Case 13:")
    operations = ["MyCalendarTwo", "book", "book", "book", "book", "book"]
    inputs = [[], [1, 10], [2, 7], [3, 19], [8, 12], [10, 20]]
    expected = [None, True, True, True, False, True]
    run_test_case(operations, inputs, expected)

if __name__ == "__main__":
    main()

