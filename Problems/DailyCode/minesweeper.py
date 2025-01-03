from typing import List
from collections import deque

class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        """
        이 함수는 주어진 미네스위퍼 보드에서 사용자의 클릭을 처리하고,
        보드를 업데이트하여 반환합니다.
        
        Parameters:
        - board (List[List[str]]): 미네스위퍼 보드
        - click (List[int]): 클릭한 위치 [행, 열]
        
        Returns:
        - List[List[str]]: 업데이트된 미네스위퍼 보드
        """
        
        # 보드의 행과 열 크기
        m, n = len(board), len(board[0])
        
        # 클릭한 위치의 행과 열
        row, col = click
        
        # 방향 벡터: 상, 하, 좌, 우, 대각선 4방향
        directions = [(-1, -1), (-1, 0), (-1, 1),
                      (0, -1),          (0, 1),
                      (1, -1),  (1, 0), (1, 1)]
        
        # 클릭한 위치가 지뢰인 경우
        if board[row][col] == 'M':
            board[row][col] = 'X'
            return board
        
        # BFS를 위한 큐 초기화
        queue = deque()
        queue.append((row, col))
        
        while queue:
            r, c = queue.popleft()
            
            # 현재 위치가 이미 방문된 경우 건너뜀
            if board[r][c] != 'E':
                continue
            
            # 주변에 있는 지뢰의 개수를 셈
            mine_count = 0
            neighbors = []
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n:
                    if board[nr][nc] == 'M':
                        mine_count += 1
                    elif board[nr][nc] == 'E':
                        neighbors.append((nr, nc))
            
            # 주변에 지뢰가 있는 경우
            if mine_count > 0:
                board[r][c] = str(mine_count)
            else:
                # 주변에 지뢰가 없는 경우 'B'로 표시하고 인접한 'E'들을 큐에 추가
                board[r][c] = 'B'
                for nr, nc in neighbors:
                    queue.append((nr, nc))
        
        return board

# 테스트를 위한 메인 함수 (선택 사항)
if __name__ == "__main__":
    solution = Solution()
    
    # 예제 1
    board1 = [
        ["E","E","E","E","E"],
        ["E","E","M","E","E"],
        ["E","E","E","E","E"],
        ["E","E","E","E","E"]
    ]
    click1 = [3, 0]
    updated_board1 = solution.updateBoard(board1, click1)
    print("예제 1 출력:")
    for row in updated_board1:
        print(row)
    # 예상 출력:
    # ["B","1","E","1","B"]
    # ["B","1","M","1","B"]
    # ["B","1","1","1","B"]
    # ["B","B","B","B","B"]
    
    print("\n-------------------\n")
    
    # 예제 2
    board2 = [
        ["B","1","E","1","B"],
        ["B","1","M","1","B"],
        ["B","1","1","1","B"],
        ["B","B","B","B","B"]
    ]
    click2 = [1, 2]
    updated_board2 = solution.updateBoard(board2, click2)
    print("예제 2 출력:")
    for row in updated_board2:
        print(row)
    # 예상 출력:
    # ["B","1","E","1","B"]
    # ["B","1","X","1","B"]
    # ["B","1","1","1","B"]
    # ["B","B","B","B","B"]
    
    print("\n-------------------\n")
    
    # 추가 테스트 케이스 1
    board3 = [
        ["E","E","E","E"],
        ["E","M","M","E"],
        ["E","E","E","E"],
        ["E","E","E","E"]
    ]
    click3 = [0, 0]
    updated_board3 = solution.updateBoard(board3, click3)
    print("추가 테스트 케이스 1 출력:")
    for row in updated_board3:
        print(row)
    # 예상 출력:
    # ["B","2","M","E"]
    # ["E","M","M","E"]
    # ["E","E","E","E"]
    # ["E","E","E","E"]
