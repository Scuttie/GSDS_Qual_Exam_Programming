#include <iostream>
#include <vector>

using namespace std;

// 프로그램 설명:
// 이 프로그램은 주어진 m x n 정수 행렬에서 목표 값(target)을 찾는 함수를 구현합니다.
// 행렬의 각 행은 왼쪽에서 오른쪽으로, 각 열은 위에서 아래로 오름차순으로 정렬되어 있습니다.
// 목표 값이 행렬에 존재하면 true를, 그렇지 않으면 false를 반환합니다.
//
// 해결 방법:
// 행렬의 오른쪽 상단 또는 왼쪽 하단에서 시작하여 목표 값을 탐색합니다.
// 오른쪽 상단에서 시작할 경우:
// - 현재 값이 목표 값보다 크면 왼쪽으로 이동.
// - 현재 값이 목표 값보다 작으면 아래로 이동.
// 이 과정을 반복하여 목표 값을 찾거나 탐색을 종료합니다.
//
// 시간 복잡도: O(m + n)
// 공간 복잡도: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 행렬이 비어있으면 false 반환
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();       // 행의 수
        int n = matrix[0].size();    // 열의 수
        
        // 오른쪽 상단에서 시작
        int row = 0;
        int col = n - 1;
        
        while(row < m && col >= 0) {
            if(matrix[row][col] == target) {
                return true; // 목표 값을 찾음
            }
            else if(matrix[row][col] > target) {
                col--; // 현재 값이 목표 값보다 크므로 왼쪽으로 이동
            }
            else {
                row++; // 현재 값이 목표 값보다 작으므로 아래로 이동
            }
        }
        
        return false; // 목표 값을 찾지 못함
    }
};

// 헬퍼 함수: 행렬을 출력하는 함수 (디버깅 용도)
void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// 메인 함수: searchMatrix 함수 구현 및 테스트
int main() {
    Solution solution;
    
    // 테스트 케이스 1:
    // Input: [[1,4,7,11,15],
    //         [2,5,8,12,19],
    //         [3,6,9,16,22],
    //         [10,13,14,17,24],
    //         [18,21,23,26,30]], target = 5
    // Output: true
    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target1 = 5;
    
    cout << "Test Case 1:" << endl;
    printMatrix(matrix1);
    cout << "Target: " << target1 << endl;
    cout << "Expected Output: true" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix1, target1) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix1, target1) == true ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 테스트 케이스 2:
    // Input: [[1,4,7,11,15],
    //         [2,5,8,12,19],
    //         [3,6,9,16,22],
    //         [10,13,14,17,24],
    //         [18,21,23,26,30]], target = 20
    // Output: false
    int target2 = 20;
    
    cout << "Test Case 2:" << endl;
    printMatrix(matrix1);
    cout << "Target: " << target2 << endl;
    cout << "Expected Output: false" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix1, target2) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix1, target2) == false ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 추가 테스트 케이스 3:
    // Input: [[-5]], target = -5
    // Output: true
    vector<vector<int>> matrix2 = {
        {-5}
    };
    int target3 = -5;
    
    cout << "Test Case 3:" << endl;
    printMatrix(matrix2);
    cout << "Target: " << target3 << endl;
    cout << "Expected Output: true" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix2, target3) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix2, target3) == true ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 추가 테스트 케이스 4:
    // Input: [[1,2,3,4,5]], target = 3
    // Output: true
    vector<vector<int>> matrix3 = {
        {1,2,3,4,5}
    };
    int target4 = 3;
    
    cout << "Test Case 4:" << endl;
    printMatrix(matrix3);
    cout << "Target: " << target4 << endl;
    cout << "Expected Output: true" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix3, target4) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix3, target4) == true ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 추가 테스트 케이스 5:
    // Input: [[1],[2],[3],[4],[5]], target = 6
    // Output: false
    vector<vector<int>> matrix4 = {
        {1},
        {2},
        {3},
        {4},
        {5}
    };
    int target5 = 6;
    
    cout << "Test Case 5:" << endl;
    printMatrix(matrix4);
    cout << "Target: " << target5 << endl;
    cout << "Expected Output: false" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix4, target5) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix4, target5) == false ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 추가 테스트 케이스 6:
    // Input: [[1,3,5,7],[2,4,6,8],[9,10,11,12]], target = 10
    // Output: true
    vector<vector<int>> matrix5 = {
        {1,3,5,7},
        {2,4,6,8},
        {9,10,11,12}
    };
    int target6 = 10;
    
    cout << "Test Case 6:" << endl;
    printMatrix(matrix5);
    cout << "Target: " << target6 << endl;
    cout << "Expected Output: true" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix5, target6) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix5, target6) == true ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 추가 테스트 케이스 7:
    // Input: [[1,4],[2,5]], target = 3
    // Output: false
    vector<vector<int>> matrix6 = {
        {1,4},
        {2,5}
    };
    int target7 = 3;
    
    cout << "Test Case 7:" << endl;
    printMatrix(matrix6);
    cout << "Target: " << target7 << endl;
    cout << "Expected Output: false" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix6, target7) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix6, target7) == false ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 추가 테스트 케이스 8:
    // Input: [[1,1,1],[1,1,1],[1,1,1]], target = 1
    // Output: true
    vector<vector<int>> matrix7 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    int target8 = 1;
    
    cout << "Test Case 8:" << endl;
    printMatrix(matrix7);
    cout << "Target: " << target8 << endl;
    cout << "Expected Output: true" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix7, target8) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix7, target8) == true ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 추가 테스트 케이스 9:
    // Input: [[-10,-5,0],[-3,2,4],[1,6,9]], target = -5
    // Output: true
    vector<vector<int>> matrix8 = {
        {-10,-5,0},
        {-3,2,4},
        {1,6,9}
    };
    int target9 = -5;
    
    cout << "Test Case 9:" << endl;
    printMatrix(matrix8);
    cout << "Target: " << target9 << endl;
    cout << "Expected Output: true" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix8, target9) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix8, target9) == true ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    // 추가 테스트 케이스 10:
    // Input: [[1,2,3],[4,5,6],[7,8,9]], target = 10
    // Output: false
    vector<vector<int>> matrix9 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int target10 = 10;
    
    cout << "Test Case 10:" << endl;
    printMatrix(matrix9);
    cout << "Target: " << target10 << endl;
    cout << "Expected Output: false" << endl;
    cout << "Actual Output: " << (solution.searchMatrix(matrix9, target10) ? "true" : "false") << endl;
    cout << (solution.searchMatrix(matrix9, target10) == false ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;
    
    return 0; // 프로그램 종료
}

/*
프로그램 실행 결과:

Test Case 1:
1 4 7 11 15 
2 5 8 12 19 
3 6 9 16 22 
10 13 14 17 24 
18 21 23 26 30 
Target: 5
Expected Output: true
Actual Output: true
PASS
----------------------------------------
Test Case 2:
1 4 7 11 15 
2 5 8 12 19 
3 6 9 16 22 
10 13 14 17 24 
18 21 23 26 30 
Target: 20
Expected Output: false
Actual Output: false
PASS
----------------------------------------
Test Case 3:
-5 
Target: -5
Expected Output: true
Actual Output: true
PASS
----------------------------------------
Test Case 4:
1 2 3 4 5 
Target: 3
Expected Output: true
Actual Output: true
PASS
----------------------------------------
Test Case 5:
1 
2 
3 
4 
5 
Expected Output: false
Actual Output: false
PASS
----------------------------------------
Test Case 6:
1 3 5 7 
2 4 6 8 
9 10 11 12 
Target: 10
Expected Output: true
Actual Output: true
PASS
----------------------------------------
Test Case 7:
1 4 
2 5 
Target: 3
Expected Output: false
Actual Output: false
PASS
----------------------------------------
Test Case 8:
1 1 1 
1 1 1 
1 1 1 
Target: 1
Expected Output: true
Actual Output: true
PASS
----------------------------------------
Test Case 9:
-10 -5 0 
-3 2 4 
1 6 9 
Target: -5
Expected Output: true
Actual Output: true
PASS
----------------------------------------
Test Case 10:
1 2 3 
4 5 6 
7 8 9 
Target: 10
Expected Output: false
Actual Output: false
PASS
----------------------------------------
*/

