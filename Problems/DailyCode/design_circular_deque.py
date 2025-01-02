# 프로그램 설명:
# 이 프로그램은 원형 이중 끝 큐(Circular Deque)를 구현한 MyCircularDeque 클래스를 제공합니다.
# 원형 이중 끝 큐는 양쪽 끝에서 삽입과 삭제가 가능한 자료구조로, 고정된 크기를 가집니다.
# 이 구현에서는 배열을 사용하여 큐를 관리하며, front와 rear 포인터를 활용하여 효율적으로 동작합니다.
#
# 클래스 MyCircularDeque는 다음과 같은 메서드를 포함합니다:
# - __init__(k): 큐의 최대 크기를 k로 초기화합니다.
# - insertFront(value): 큐의 앞쪽에 값을 삽입합니다. 성공 시 True, 실패 시 False를 반환합니다.
# - insertLast(value): 큐의 뒤쪽에 값을 삽입합니다. 성공 시 True, 실패 시 False를 반환합니다.
# - deleteFront(): 큐의 앞쪽에서 값을 삭제합니다. 성공 시 True, 실패 시 False를 반환합니다.
# - deleteLast(): 큐의 뒤쪽에서 값을 삭제합니다. 성공 시 True, 실패 시 False를 반환합니다.
# - getFront(): 큐의 앞쪽 값을 반환합니다. 큐가 비어있으면 -1을 반환합니다.
# - getRear(): 큐의 뒤쪽 값을 반환합니다. 큐가 비어있으면 -1을 반환합니다.
# - isEmpty(): 큐가 비어있는지 여부를 반환합니다.
# - isFull(): 큐가 가득 찼는지 여부를 반환합니다.

class MyCircularDeque:
    def __init__(self, k: int):
        """
        MyCircularDeque 클래스를 초기화합니다.
        
        :param k: 큐의 최대 크기
        """
        self.capacity = k + 1  # 원형 큐의 구분을 위해 한 칸 여유를 둡니다.
        self.data = [0] * self.capacity  # 큐를 저장할 배열
        self.front = 0  # 큐의 앞쪽 포인터
        self.rear = 0   # 큐의 뒤쪽 포인터

    def insertFront(self, value: int) -> bool:
        """
        큐의 앞쪽에 값을 삽입합니다.
        
        :param value: 삽입할 값
        :return: 삽입 성공 시 True, 실패 시 False
        """
        if self.isFull():
            return False  # 큐가 가득 찼다면 삽입 불가
        self.front = (self.front - 1 + self.capacity) % self.capacity  # 앞쪽 포인터 이동
        self.data[self.front] = value  # 값 삽입
        return True

    def insertLast(self, value: int) -> bool:
        """
        큐의 뒤쪽에 값을 삽입합니다.
        
        :param value: 삽입할 값
        :return: 삽입 성공 시 True, 실패 시 False
        """
        if self.isFull():
            return False  # 큐가 가득 찼다면 삽입 불가
        self.data[self.rear] = value  # 값 삽입
        self.rear = (self.rear + 1) % self.capacity  # 뒤쪽 포인터 이동
        return True

    def deleteFront(self) -> bool:
        """
        큐의 앞쪽에서 값을 삭제합니다.
        
        :return: 삭제 성공 시 True, 실패 시 False
        """
        if self.isEmpty():
            return False  # 큐가 비어있다면 삭제 불가
        self.front = (self.front + 1) % self.capacity  # 앞쪽 포인터 이동
        return True

    def deleteLast(self) -> bool:
        """
        큐의 뒤쪽에서 값을 삭제합니다.
        
        :return: 삭제 성공 시 True, 실패 시 False
        """
        if self.isEmpty():
            return False  # 큐가 비어있다면 삭제 불가
        self.rear = (self.rear - 1 + self.capacity) % self.capacity  # 뒤쪽 포인터 이동
        return True

    def getFront(self) -> int:
        """
        큐의 앞쪽 값을 반환합니다.
        
        :return: 앞쪽 값, 큐가 비어있으면 -1
        """
        if self.isEmpty():
            return -1  # 큐가 비어있다면 -1 반환
        return self.data[self.front]

    def getRear(self) -> int:
        """
        큐의 뒤쪽 값을 반환합니다.
        
        :return: 뒤쪽 값, 큐가 비어있으면 -1
        """
        if self.isEmpty():
            return -1  # 큐가 비어있다면 -1 반환
        return self.data[(self.rear - 1 + self.capacity) % self.capacity]

    def isEmpty(self) -> bool:
        """
        큐가 비어있는지 확인합니다.
        
        :return: 큐가 비어있으면 True, 아니면 False
        """
        return self.front == self.rear

    def isFull(self) -> bool:
        """
        큐가 가득 찼는지 확인합니다.
        
        :return: 큐가 가득 찼으면 True, 아니면 False
        """
        return (self.rear + 1) % self.capacity == self.front

# 테스트를 위한 메인 함수
def main():
    # 테스트 케이스 목록
    test_cases = [
        {
            'operations': ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"],
            'inputs': [[3], [1], [2], [3], [4], [], [], [], [4], []],
            'expected': [None, True, True, True, False, 2, True, True, True, 4]
        },
        {
            'operations': ["MyCircularDeque", "insertFront", "insertFront", "deleteLast", "getRear", "getFront"],
            'inputs': [[2], [1], [2], [], [], []],
            'expected': [None, True, True, True, 1, 2]
        },
        {
            'operations': ["MyCircularDeque", "insertLast", "insertFront", "insertLast", "insertFront", "getFront", "getRear", "isEmpty", "isFull"],
            'inputs': [[4], [1], [2], [3], [4], [], [], [], []],
            'expected': [None, True, True, True, True, 2, 4, False, True]
        },
        {
            'operations': ["MyCircularDeque", "insertFront", "deleteFront", "deleteLast", "isEmpty"],
            'inputs': [[1], [10], [], [], []],
            'expected': [None, True, True, False, True]
        },
        {
            'operations': ["MyCircularDeque", "insertLast", "insertLast", "insertLast", "insertLast", "isFull", "getRear"],
            'inputs': [[3], [1], [2], [3], [4], [], []],
            'expected': [None, True, True, True, False, True, 3]
        },
        {
            'operations': ["MyCircularDeque", "insertFront", "insertLast", "getFront", "getRear"],
            'inputs': [[2], [5], [10], [], []],
            'expected': [None, True, True, 5, 10]
        },
        {
            'operations': ["MyCircularDeque", "insertLast", "insertFront", "insertLast", "insertFront", "deleteFront", "deleteLast", "getFront", "getRear", "isEmpty", "isFull"],
            'inputs': [[5], [1], [2], [3], [4], [], [], [], [], [], []],
            'expected': [None, True, True, True, True, True, True, 2, 3, False, False]
        },
        {
            'operations': ["MyCircularDeque", "insertLast", "insertLast", "deleteFront", "getFront", "getRear"],
            'inputs': [[2], [10], [20], [], [], []],
            'expected': [None, True, True, True, 20, 20]
        },
        {
            'operations': ["MyCircularDeque", "insertFront", "insertFront", "insertLast", "deleteLast", "getRear"],
            'inputs': [[3], [5], [6], [7], [], []],
            'expected': [None, True, True, True, True, 6]
        },
        {
            'operations': ["MyCircularDeque", "insertLast", "insertLast", "insertLast", "deleteFront", "deleteFront", "getFront", "isEmpty"],
            'inputs': [[3], [1], [2], [3], [], [], [], []],
            'expected': [None, True, True, True, True, True, 3, False]
        },
    ]

    for idx, test in enumerate(test_cases, 1):
        operations = test['operations']
        inputs = test['inputs']
        expected = test['expected']
        my_deque = None
        actual = []
        
        for op, inp in zip(operations, inputs):
            if op == "MyCircularDeque":
                my_deque = MyCircularDeque(inp[0])
                actual.append(None)  # 생성자는 반환값이 없으므로 None을 추가
            elif op == "insertFront":
                result = my_deque.insertFront(inp[0])
                actual.append(result)
            elif op == "insertLast":
                result = my_deque.insertLast(inp[0])
                actual.append(result)
            elif op == "deleteFront":
                result = my_deque.deleteFront()
                actual.append(result)
            elif op == "deleteLast":
                result = my_deque.deleteLast()
                actual.append(result)
            elif op == "getFront":
                result = my_deque.getFront()
                actual.append(result)
            elif op == "getRear":
                result = my_deque.getRear()
                actual.append(result)
            elif op == "isEmpty":
                result = my_deque.isEmpty()
                actual.append(result)
            elif op == "isFull":
                result = my_deque.isFull()
                actual.append(result)
        
        # 결과 비교
        pass_flag = actual == expected
        
        # 결과 출력
        print(f"Test Case {idx}:")
        print(f"Operations: {operations}")
        print(f"Inputs: {inputs}")
        print(f"Expected Output: {expected}")
        print(f"Actual Output:   {actual}")
        print("PASS" if pass_flag else "FAIL")
        print("-" * 50)

    # 추가 테스트 케이스 11:
    # ["MyCircularDeque", "insertFront", "insertLast", "deleteFront", "getFront", "isEmpty"]
    # [[2], [10], [20], [], [], []]
    print("Additional Test Case 11:")
    operations = ["MyCircularDeque", "insertFront", "insertLast", "deleteFront", "getFront", "isEmpty"]
    inputs = [[2], [10], [20], [], [], []]
    expected = [None, True, True, True, 20, False]
    my_deque = None
    actual = []
    for op, inp in zip(operations, inputs):
        if op == "MyCircularDeque":
            my_deque = MyCircularDeque(inp[0])
            actual.append(None)
        elif op == "insertFront":
            result = my_deque.insertFront(inp[0])
            actual.append(result)
        elif op == "insertLast":
            result = my_deque.insertLast(inp[0])
            actual.append(result)
        elif op == "deleteFront":
            result = my_deque.deleteFront()
            actual.append(result)
        elif op == "getFront":
            result = my_deque.getFront()
            actual.append(result)
        elif op == "isEmpty":
            result = my_deque.isEmpty()
            actual.append(result)
    pass_flag = actual == expected
    print(f"Operations: {operations}")
    print(f"Inputs: {inputs}")
    print(f"Expected Output: {expected}")
    print(f"Actual Output:   {actual}")
    print("PASS" if pass_flag else "FAIL")
    print("-" * 50)

    # 추가 테스트 케이스 12:
    # ["MyCircularDeque", "insertLast", "insertLast", "deleteFront", "getFront", "getRear"]
    # [[3], [1], [2], [], [], []]
    print("Additional Test Case 12:")
    operations = ["MyCircularDeque", "insertLast", "insertLast", "deleteFront", "getFront", "getRear"]
    inputs = [[3], [1], [2], [], [], []]
    expected = [None, True, True, True, 2, 2]
    my_deque = None
    actual = []
    for op, inp in zip(operations, inputs):
        if op == "MyCircularDeque":
            my_deque = MyCircularDeque(inp[0])
            actual.append(None)
        elif op == "insertLast":
            result = my_deque.insertLast(inp[0])
            actual.append(result)
        elif op == "deleteFront":
            result = my_deque.deleteFront()
            actual.append(result)
        elif op == "getFront":
            result = my_deque.getFront()
            actual.append(result)
        elif op == "getRear":
            result = my_deque.getRear()
            actual.append(result)
    pass_flag = actual == expected
    print(f"Operations: {operations}")
    print(f"Inputs: {inputs}")
    print(f"Expected Output: {expected}")
    print(f"Actual Output:   {actual}")
    print("PASS" if pass_flag else "FAIL")
    print("-" * 50)

if __name__ == "__main__":
    main()

