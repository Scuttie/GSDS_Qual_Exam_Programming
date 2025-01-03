#include <iostream>
#include <vector>

using namespace std;

// 솔루션 클래스 정의
class Solution {
public:
    /**
     * 보드에서 전투기의 개수를 세는 함수
     * 
     * @param board 전투기와 빈 공간을 나타내는 2D 벡터
     * @return 보드에 있는 전투기의 총 개수
     */
    int countBattleships(vector<vector<char>>& board) {
        // 보드의 행 수와 열 수를 저장
        int m = board.size();
        if (m == 0) return 0; // 보드가 비어있으면 전투기 개수는 0
        int n = board[0].size();
        if (n == 0) return 0; // 보드가 비어있으면 전투기 개수는 0
        
        int count = 0; // 전투기 개수를 세기 위한 변수 초기화
        
        // 보드의 모든 셀을 순회
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 현재 셀이 전투기('X')인지 확인
                if (board[i][j] == 'X') {
                    // 위쪽 셀 또는 왼쪽 셀이 'X'인 경우, 현재 'X'는 이미 세어진 전투기의 일부이므로 건너뜀
                    if (i > 0 && board[i-1][j] == 'X') continue;
                    if (j > 0 && board[i][j-1] == 'X') continue;
                    
                    // 새로운 전투기의 시작점을 발견했으므로 카운트 증가
                    count++;
                }
            }
        }
        
        return count; // 전투기 총 개수 반환
    }
};

// 테스트를 위한 메인 함수
int main() {
    Solution solution;
    
    // 예제 1
    vector<vector<char>> board1 = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    };
    cout << "예제 1 입력: [[" << "X" << "," << "." << "," << "." << "," << "X" << "],"
         << "[" << "." << "," << "." << "," << "." << "," << "X" << "],"
         << "[" << "." << "," << "." << "," << "." << "," << "X" << "]]" << endl;
    cout << "출력: " << solution.countBattleships(board1) << endl << endl; // 출력: 2
    
    // 예제 2
    vector<vector<char>> board2 = {
        {'.'}
    };
    cout << "예제 2 입력: [[" << "." << "]]" << endl;
    cout << "출력: " << solution.countBattleships(board2) << endl << endl; // 출력: 0
    
    // 추가 테스트 케이스 1
    vector<vector<char>> board3 = {
        {'X', 'X', 'X', '.', 'X'},
        {'X', '.', 'X', '.', '.'},
        {'X', 'X', 'X', '.', 'X'},
        {'.', '.', '.', '.', '.'},
        {'X', 'X', '.', 'X', 'X'}
    };
    cout << "추가 테스트 케이스 1 입력: [[" 
         << "X,X,X,.,X],"
         << "[X,.,X,.,.],"
         << "[X,X,X,.,X],"
         << "[.,.,.,.,.],"
         << "[X,X,.,X,X]]" << endl;
    cout << "출력: " << solution.countBattleships(board3) << endl << endl; // 출력: 6
    
    // 추가 테스트 케이스 2
    vector<vector<char>> board4 = {
        {'X', '.', 'X', '.', 'X'},
        {'.', 'X', '.', 'X', '.'},
        {'X', '.', 'X', '.', 'X'}
    };
    cout << "추가 테스트 케이스 2 입력: [[" 
         << "X,.,X,.,X],"
         << "[.,X,.,X,."],"
         << "[X,.,X,.,X]]" << endl;
    cout << "출력: " << solution.countBattleships(board4) << endl; // 출력: 5
    
    return 0;
}
