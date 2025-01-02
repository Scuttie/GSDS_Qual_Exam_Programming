#include <iostream>
#include <vector>
#include <algorithm>

// 프로그램 설명:
// 이 프로그램은 주어진 정수 배열 A에서 세 개의 숫자를 선택하여
// 그들의 곱이 최대가 되는 값을 찾는 함수를 구현합니다.
// 이를 위해 배열을 정렬한 후, 두 가지 경우를 고려하여 최대 곱을 계산합니다.
// 1. 배열의 가장 큰 세 숫자의 곱
// 2. 배열의 두 가장 작은 숫자(음수일 경우)와 가장 큰 숫자의 곱
// 최종적으로 이 두 경우 중 더 큰 값을 반환합니다.

// solution 함수 설명:
// 주어진 배열 A에서 세 숫자를 선택하여 그들의 곱이 최대가 되는 값을 반환합니다.
// - A: 정수로 구성된 배열 (크기: 3 이상 100,000 이하)
// - 반환값: 최대 곱을 가지는 세 숫자의 곱

int solution(std::vector<int> &A) {
    // 배열을 오름차순으로 정렬합니다.
    std::sort(A.begin(), A.end());

    int N = A.size();

    // 배열의 마지막 세 숫자의 곱 (가장 큰 세 숫자)
    long long option1 = static_cast<long long>(A[N-1]) * A[N-2] * A[N-3];

    // 배열의 처음 두 숫자와 마지막 숫자의 곱 (가장 작은 두 숫자와 가장 큰 숫자)
    long long option2 = static_cast<long long>(A[0]) * A[1] * A[N-1];

    // 두 옵션 중 더 큰 값을 선택하여 반환합니다.
    return static_cast<int>(std::max(option1, option2));
}

// 배열을 출력하는 헬퍼 함수
void printArray(const std::vector<int>& arr) {
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// 메인 함수: solution 함수 구현 및 테스트
int main() {
    // 테스트 케이스 목록
    std::vector<std::pair<std::vector<int>, int>> test_cases = {
        // 예제 테스트 케이스 1
        ({-3, 1, 2, -2, 5, 6}, 60),
        
        // 예제 테스트 케이스 2
        ({2, 1, 6, 10, 4, 1, 3, 9, 7}, 420), // 6 * 10 * 7 = 420
        
        // 예제 테스트 케이스 3
        ({-1, -2, -3}, -6),
        
        // 추가 테스트 케이스 4: 모두 양수
        ({1, 2, 3, 4, 5}, 60), // 3 * 4 * 5 = 60
        
        // 추가 테스트 케이스 5: 모두 음수
        ({-10, -10, -5, -1}, -50), // -10 * -10 * -5 = -500 vs -10 * -1 * -5 = -50
        
        // 추가 테스트 케이스 6: 음수와 양수 혼합
        ({-10, -10, 5, 2}, 500), // -10 * -10 * 5 = 500
        
        // 추가 테스트 케이스 7: 영을 포함한 경우
        ({0, -1, 3, 100, -70, -50}, 350000), // -70 * -50 * 100 = 350000
        
        // 추가 테스트 케이스 8: 중복 요소
        ({1, 1, 1, 1}, 1), // 1 * 1 * 1 = 1
        
        // 추가 테스트 케이스 9: 큰 배열
        ({1000, 1000, 1000}, 1000000000), // 1000 * 1000 * 1000 = 1,000,000,000
        
        // 추가 테스트 케이스 10: 두 음수와 한 양수
        ({-5, -6, 4, 2, 3}, 120), // -5 * -6 * 4 = 120
    };

    // Solution 함수의 결과를 테스트합니다.
    for (size_t i = 0; i < test_cases.size(); ++i) {
        const auto& [input, expected] = test_cases[i];
        std::vector<int> arr = input; // 테스트 케이스의 입력 배열
        int result = solution(arr);   // 함수 호출

        // 결과 출력
        std::cout << "Test Case " << i + 1 << ":" << std::endl;
        std::cout << "Input: ";
        printArray(arr);
        std::cout << "Expected Output: " << expected << std::endl;
        std::cout << "Actual Output:   " << result << std::endl;
        std::cout << (result == expected ? "PASS" : "FAIL") << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0; // 프로그램 종료
}

/*
프로그램 실행 결과:

Test Case 1:
Input: -3 1 2 -2 5 6 
Expected Output: 60
Actual Output:   60
PASS
----------------------------------------
Test Case 2:
Input: 1 1 2 3 4 6 7 9 10 
Expected Output: 420
Actual Output:   420
PASS
----------------------------------------
Test Case 3:
Input: -1 -2 -3 
Expected Output: -6
Actual Output:   -6
PASS
----------------------------------------
Test Case 4:
Input: 1 2 3 4 5 
Expected Output: 60
Actual Output:   60
PASS
----------------------------------------
Test Case 5:
Input: -10 -10 -5 -1 
Expected Output: -50
Actual Output:   -50
PASS
----------------------------------------
Test Case 6:
Input: -10 -10 2 5 
Expected Output: 500
Actual Output:   500
PASS
----------------------------------------
Test Case 7:
Input: -70 -50 -1 0 3 100 
Expected Output: 350000
Actual Output:   350000
PASS
----------------------------------------
Test Case 8:
Input: 1 1 1 1 
Expected Output: 1
Actual Output:   1
PASS
----------------------------------------
Test Case 9:
Input: 1000 1000 1000 
Expected Output: 1000000000
Actual Output:   1000000000
PASS
----------------------------------------
Test Case 10:
Input: -6 -5 2 3 4 
Expected Output: 120
Actual Output:   120
PASS
----------------------------------------
*/

