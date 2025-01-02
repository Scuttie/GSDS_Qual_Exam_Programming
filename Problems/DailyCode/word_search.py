"""
문제 설명:

m x n 크기의 문자 그리드(board)와 문자열 word가 주어졌을 때, word가 그리드 내에 존재하면 True를, 그렇지 않으면 False를 반환하는 문제입니다.

word는 연속적으로 인접한 셀의 문자로 구성될 수 있으며, 인접한 셀은 수평 또는 수직으로 인접한 셀을 의미합니다. 같은 문자 셀을 여러 번 사용할 수 없습니다.

예를 들어:
- 예제 1:
    입력: board = [["A","B","C","E"],
                  ["S","F","C","S"],
                  ["A","D","E","E"]],
          word = "ABCCED"
    출력: True
    설명: 단어 "ABCCED"는 A -> B -> C -> C -> E -> D 경로를 따라 그리드 내에 존재합니다.

- 예제 2:
    입력: board = [["A","B","C","E"],
                  ["S","F","C","S"],
                  ["A","D","E","E"]],
          word = "SEE"
    출력: True
    설명: 단어 "SEE"는 S -> E -> E 경로를 따라 그리드 내에 존재합니다.

- 예제 3:
    입력: board = [["A","B","C","E"],
                  ["S","F","C","S"],
                  ["A","D","E","E"]],
          word = "ABCB"
    출력: False
    설명: 단어 "ABCB"는 그리드 내에 존재하지 않습니다.

제약 조건:
- m == board.length
- n == board[i].length
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- board와 word는 대문자와 소문자로만 구성됩니다.

추가 질문:
그리드의 크기가 더 클 경우, 검색 가지치기(search pruning)를 사용하여 솔루션을 더 빠르게 만들 수 있을까요?

해결 방법:
이 문제는 깊이 우선 탐색(DFS)과 백트래킹을 사용하여 해결할 수 있습니다. 그리드를 순회하면서 각 셀을 시작점으로 삼아 단어의 첫 글자와 일치하는지 확인합니다. 일치할 경우, 인접한 셀로 이동하며 단어의 다음 글자를 찾습니다. 셀을 방문할 때는 해당 셀을 사용 중임을 표시하고, 탐색이 끝난 후에는 다시 표시를 해제합니다.

검색 가지치기를 위해 다음과 같은 최적화를 적용할 수 있습니다:
1. 현재 셀과 단어의 글자가 일치하지 않으면 바로 반환.
2. 남은 셀의 개수가 단어의 남은 글자 수보다 적으면 더 이상 탐색하지 않음.

"""

from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        """
        주어진 m x n 그리드 내에 단어가 존재하는지 여부를 판단합니다.
        단어는 인접한 셀을 통해 구성되며, 같은 셀을 여러 번 사용할 수 없습니다.
        
        :param board: List[List[str]] - 문자 그리드
        :param word: str - 찾고자 하는 단어
        :return: bool - 단어가 그리드 내에 존재하면 True, 아니면 False
        """
        if not board or not board[0]:
            return False  # 그리드가 비어있으면 False 반환

        self.rows = len(board)
        self.cols = len(board[0])
        self.board = board
        self.word = word
        self.word_length = len(word)

        for i in range(self.rows):
            for j in range(self.cols):
                if self.board[i][j] == self.word[0]:  # 단어의 첫 글자와 일치하는 셀 찾기
                    if self.dfs(i, j, 0):
                        return True  # 단어를 찾으면 True 반환
        return False  # 모든 셀을 탐색했으나 단어를 찾지 못하면 False 반환

    def dfs(self, i: int, j: int, index: int) -> bool:
        """
        현재 셀에서부터 단어의 index번째 글자를 찾는 DFS 함수입니다.
        
        :param i: int - 현재 행
        :param j: int - 현재 열
        :param index: int - 단어에서 현재 찾고 있는 글자의 인덱스
        :return: bool - 단어를 찾으면 True, 아니면 False
        """
        # 단어의 모든 글자를 찾았으면 True 반환
        if index == self.word_length - 1:
            return True

        # 현재 셀을 방문했음을 표시 (임시로 변경)
        temp = self.board[i][j]
        self.board[i][j] = '#'  # 방문 표시

        # 상하좌우 인접 셀을 탐색
        for x, y in [(i-1,j), (i+1,j), (i,j-1), (i,j+1)]:
            if 0 <= x < self.rows and 0 <= y < self.cols and self.board[x][y] == self.word[index + 1]:
                if self.dfs(x, y, index + 1):
                    return True  # 단어의 다음 글자를 찾았으면 True 반환

        # 탐색이 끝났으면 방문 표시를 원래대로 되돌림
        self.board[i][j] = temp
        return False  # 단어를 찾지 못했으면 False 반환

# 테스트를 위한 헬퍼 함수
def run_test_case(test_num: int, board: List[List[str]], word: str, expected: bool):
    """
    주어진 테스트 케이스를 실행하고 결과를 출력합니다.
    
    :param test_num: int - 테스트 케이스 번호
    :param board: List[List[str]] - 문자 그리드
    :param word: str - 찾고자 하는 단어
    :param expected: bool - 예상되는 결과
    """
    solution = Solution()
    result = solution.exist(board, word)
    print(f"테스트 케이스 {test_num}:")
    print(f"입력: board = {board}, word = \"{word}\"")
    print(f"예상 출력: {expected}")
    print(f"실제 출력: {result}")
    print("PASS" if result == expected else "FAIL")
    print("-" * 50)

# 메인 함수: 솔루션 테스트
def main():
    test_cases = [
        {
            'test_num': 1,
            'board': [["A","B","C","E"],
                      ["S","F","C","S"],
                      ["A","D","E","E"]],
            'word': "ABCCED",
            'expected': True
        },
        {
            'test_num': 2,
            'board': [["A","B","C","E"],
                      ["S","F","C","S"],
                      ["A","D","E","E"]],
            'word': "SEE",
            'expected': True
        },
        {
            'test_num': 3,
            'board': [["A","B","C","E"],
                      ["S","F","C","S"],
                      ["A","D","E","E"]],
            'word': "ABCB",
            'expected': False
        },
        {
            'test_num': 4,
            'board': [["A","B","C","E"],
                      ["S","F","E","S"],
                      ["A","D","E","E"]],
            'word': "ABCEFSADEESE",
            'expected': False
        },
        {
            'test_num': 5,
            'board': [["A","B","C","E"],
                      ["S","F","C","S"],
                      ["A","D","E","E"]],
            'word': "ABFSF",
            'expected': False
        },
        {
            'test_num': 6,
            'board': [["A","A","A","A"],
                      ["A","A","A","A"],
                      ["A","A","A","A"]],
            'word': "AAAA",
            'expected': True
        },
        {
            'test_num': 7,
            'board': [["C","A","A"],
                      ["A","A","A"],
                      ["B","C","D"]],
            'word': "AAB",
            'expected': True
        },
        {
            'test_num': 8,
            'board': [["a","b"],
                      ["c","d"]],
            'word': "abcd",
            'expected': False
        },
        {
            'test_num': 9,
            'board': [["A","B","C","E"],
                      ["S","F","C","S"],
                      ["A","D","E","E"]],
            'word': "ABCEFSADEESE",
            'expected': False
        },
        {
            'test_num': 10,
            'board': [["a","a"]],
            'word': "aaa",
            'expected': False
        },
    ]
    
    for test in test_cases:
        run_test_case(
            test['test_num'],
            test['board'],
            test['word'],
            test['expected']
        )

if __name__ == "__main__":
    main()
