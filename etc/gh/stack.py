class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        return None

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        return None

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)

# 사용 예시
if __name__ == "__main__":
    s = Stack()
    s.push(1)
    s.push(2)
    print(s.pop())  # 출력: 2
    print(s.peek())  # 출력: 1
    print(s.is_empty())  # 출력: False
