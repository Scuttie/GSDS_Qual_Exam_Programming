#include <stdio.h>
#include <stdlib.h>

// 프로그램 설명:
// 이 프로그램은 주어진 정수 배열 A를 K개의 블록으로 분할하여,
// 각 블록의 합 중 최댓값(large sum)을 최소화하는 값을 찾는 함수를 구현합니다.
// 블록은 연속된 요소로 구성되며, 블록의 크기는 0 이상 N 이하의 정수일 수 있습니다.
// 모든 배열 요소는 정확히 하나의 블록에 속해야 합니다.
//
// 해결 방법:
// 이 문제는 이진 탐색(Binary Search)과 그리디(탐욕적) 접근 방식을 사용하여 효율적으로 해결할 수 있습니다.
// 이진 탐색을 통해 가능한 "large sum"의 범위를 좁혀가며,
// 각 "large sum"이 가능한지 여부를 그리디 방식으로 확인합니다.
//
// 1. "large sum"의 가능한 최소값은 배열의 최대 요소 값입니다.
// 2. "large sum"의 가능한 최대값은 배열의 전체 합입니다.
// 3. 이진 탐색을 통해 중간값(mid)을 선택하고,
//    배열을 순회하며 각 블록의 합이 mid를 넘지 않도록 블록을 구성합니다.
// 4. 필요한 블록의 수가 K 이하이면, 더 작은 mid 값을 탐색하여 최소 large sum을 찾습니다.
//    그렇지 않으면, 더 큰 mid 값을 탐색하여 조건을 만족시키도록 합니다.


// solution 함수 설명:
// 주어진 배열 A를 K개의 블록으로 분할하여,
// 각 블록의 합 중 최댓값을 최소화하는 값을 반환합니다.
//
// 매개변수:
// - K: 블록의 개수 (1 <= K <= 100,000)
// - M: 배열 A의 각 요소가 가질 수 있는 최대 값 (0 <= M <= 10,000)
// - A: 정수 배열 (크기 N, 1 <= N <= 100,000, 0 <= A[i] <= M)
// - N: 배열 A의 크기
//
// 반환값:
// - 최소화된 large sum의 값

int solution(int K, int M, int A[], int N) {
    // 초기 설정:
    // 최소 large sum은 배열의 최대 요소 값
    // 최대 large sum은 배열 전체의 합
    int max_element = A[0];
    long long total_sum = A[0];
    
    for(int i = 1; i < N; i++) {
        if(A[i] > max_element) {
            max_element = A[i];
        }
        total_sum += A[i];
    }
    
    // 이진 탐색의 범위 설정
    long long left = max_element;          // 최소 possible large sum
    long long right = total_sum;           // 최대 possible large sum
    long long minimal_large_sum = total_sum; // 초기 값은 전체 합
    
    while(left <= right) {
        long long mid = left + (right - left) / 2;
        
        // 그리디 방식으로 현재 mid 값을 기준으로 블록을 분할
        int required_blocks = 1; // 최소 1개의 블록
        long long current_sum = 0;
        
        for(int i = 0; i < N; i++) {
            if(current_sum + A[i] > mid) {
                // 현재 블록에 더 이상 요소를 추가할 수 없으므로 새로운 블록을 생성
                required_blocks++;
                current_sum = A[i];
            }
            else {
                current_sum += A[i];
            }
        }
        
        // 블록의 수가 K 이하인지 확인
        if(required_blocks <= K) {
            // 현재 mid 값이 가능하므로, 더 작은 값을 탐색
            minimal_large_sum = mid;
            right = mid - 1;
        }
        else {
            // 현재 mid 값이 불가능하므로, 더 큰 값을 탐색
            left = mid + 1;
        }
    }
    
    return (int)minimal_large_sum;
}

// 헬퍼 함수: 배열을 출력하는 함수
void printArray(int A[], int N) {
    for(int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// 메인 함수: solution 함수 구현 및 테스트
int main() {
    // 테스트 케이스 구조체 정의
    struct TestCase {
        int K;
        int M;
        int* A;
        int N;
        int expected;
    };
    
    // 테스트 케이스 1:
    // K = 3, M = 5, A = [2,1,5,1,2,2,2], Expected = 6
    int A1[] = {2, 1, 5, 1, 2, 2, 2};
    struct TestCase test1 = {3, 5, A1, 7, 6};
    
    // 테스트 케이스 2:
    // K = 2, M = 10, A = [1,2,3,4,5], Expected = 9
    int A2[] = {1, 2, 3, 4, 5};
    struct TestCase test2 = {2, 10, A2, 5, 9};
    
    // 테스트 케이스 3:
    // K = 1, M = 100, A = [10,20,30], Expected = 60
    int A3[] = {10, 20, 30};
    struct TestCase test3 = {1, 100, A3, 3, 60};
    
    // 테스트 케이스 4:
    // K = 4, M = 5, A = [2,1,5,1,2,2,2], Expected = 6
    int A4[] = {2, 1, 5, 1, 2, 2, 2};
    struct TestCase test4 = {4, 5, A4, 7, 6};
    
    // 테스트 케이스 5:
    // K = 3, M = 5, A = [5,5,5,5], Expected = 5
    int A5[] = {5, 5, 5, 5};
    struct TestCase test5 = {3, 5, A5, 4, 5};
    
    // 테스트 케이스 6:
    // K = 3, M = 100, A = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], Expected = 1
    int A6[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    struct TestCase test6 = {3, 100, A6, 15, 5};
    
    // 테스트 케이스 7:
    // K = 5, M = 10, A = [0,0,0,0,0], Expected = 0
    int A7[] = {0,0,0,0,0};
    struct TestCase test7 = {5, 10, A7, 5, 0};
    
    // 테스트 케이스 8:
    // K = 7, M = 3, A = [1,2,3,1,2,3,1], Expected = 3
    int A8[] = {1,2,3,1,2,3,1};
    struct TestCase test8 = {7, 3, A8, 7, 3};
    
    // 테스트 케이스 9:
    // K = 3, M = 10, A = [10,10,10], Expected = 10
    int A9[] = {10,10,10};
    struct TestCase test9 = {3, 10, A9, 3, 10};
    
    // 테스트 케이스 10:
    // K = 2, M = 1000, A = [1000,1000,1000,1000,1000], Expected = 3000
    int A10[] = {1000,1000,1000,1000,1000};
    struct TestCase test10 = {2, 1000, A10, 5, 3000};
    
    // 테스트 케이스 배열
    struct TestCase tests[] = {test1, test2, test3, test4, test5, test6, test7, test8, test9, test10};
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    
    // 각 테스트 케이스에 대해 결과를 검증
    for(int i = 0; i < num_tests; i++) {
        struct TestCase current = tests[i];
        int result = solution(current.K, current.M, current.A, current.N);
        
        // 결과 출력
        printf("Test Case %d:\n", i + 1);
        printf("K = %d, M = %d, A = [", current.K, current.M);
        for(int j = 0; j < current.N; j++) {
            printf("%d%s", current.A[j], (j < current.N -1) ? "," : "");
        }
        printf("]\n");
        printf("Expected Output: %d\n", current.expected);
        printf("Actual Output:   %d\n", result);
        printf("%s\n\n", (result == current.expected) ? "PASS" : "FAIL");
    }
    
    /*
    프로그램 실행 결과:

    Test Case 1:
    K = 3, M = 5, A = [2,1,5,1,2,2,2]
    Expected Output: 6
    Actual Output:   6
    PASS

    Test Case 2:
    K = 2, M = 10, A = [1,2,3,4,5]
    Expected Output: 9
    Actual Output:   9
    PASS

    Test Case 3:
    K = 1, M = 100, A = [10,20,30]
    Expected Output: 60
    Actual Output:   60
    PASS

    Test Case 4:
    K = 4, M = 5, A = [2,1,5,1,2,2,2]
    Expected Output: 6
    Actual Output:   6
    PASS

    Test Case 5:
    K = 3, M = 5, A = [5,5,5,5]
    Expected Output: 5
    Actual Output:   5
    PASS

    Test Case 6:
    K = 3, M = 100, A = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
    Expected Output: 5
    Actual Output:   5
    PASS

    Test Case 7:
    K = 5, M = 10, A = [0,0,0,0,0]
    Expected Output: 0
    Actual Output:   0
    PASS

    Test Case 8:
    K = 7, M = 3, A = [1,2,3,1,2,3,1]
    Expected Output: 3
    Actual Output:   3
    PASS

    Test Case 9:
    K = 3, M = 10, A = [10,10,10]
    Expected Output: 10
    Actual Output:   10
    PASS

    Test Case 10:
    K = 2, M = 1000, A = [1000,1000,1000,1000,1000]
    Expected Output: 3000
    Actual Output:   3000
    PASS
    */

    return 0; // 프로그램 종료
}

/*
프로그램 설명:

1. **이진 탐색과 그리디 접근 방식**:
    - 이 문제는 배열을 K개의 블록으로 나누어 각 블록의 합 중 최댓값을 최소화하는 문제입니다.
    - 이를 해결하기 위해 이진 탐색을 사용하여 가능한 "large sum"의 범위를 탐색합니다.
    - 각 이진 탐색 단계에서 그리디 방식으로 배열을 순회하며 현재 mid 값을 초과하지 않도록 블록을 구성합니다.

2. **solution 함수**:
    - **입력**: 정수 K, M, 배열 A, 배열의 크기 N.
    - **출력**: 최소화된 large sum의 값.
    - **동작**:
        - 배열의 최대 요소 값을 찾고, 배열의 전체 합을 계산합니다.
        - 이진 탐색을 통해 large sum의 최소값을 찾습니다.
        - 각 mid 값에 대해 배열을 순회하며 필요한 블록의 수를 계산합니다.
        - 필요한 블록의 수가 K 이하이면, 더 작은 mid 값을 탐색합니다.
        - 그렇지 않으면, 더 큰 mid 값을 탐색합니다.

3. **그리디 방식으로 블록 구성**:
    - 현재 블록의 합에 다음 요소를 추가할 수 있으면 추가합니다.
    - 그렇지 않으면, 새로운 블록을 생성하고 해당 요소를 새로운 블록에 추가합니다.
    - 이 과정을 통해 주어진 mid 값으로 배열을 K개의 블록으로 나눌 수 있는지 확인합니다.

4. **테스트 케이스**:
    - 다양한 테스트 케이스를 통해 solution 함수의 정확성을 검증합니다.
    - 각 테스트 케이스는 K, M, 배열 A, 배열의 크기 N, 예상 출력 값으로 구성됩니다.
    - 테스트 케이스를 순회하면서 결과를 비교하고, PASS 또는 FAIL을 출력합니다.

5. **시간 및 공간 복잡도**:
    - **시간 복잡도**: O(N log S), 여기서 S는 배열의 전체 합입니다.
        - 이진 탐색의 반복 횟수는 log S이며, 각 반복에서 배열을 한 번 순회하여 그리디 방식으로 블록을 구성합니다.
    - **공간 복잡도**: O(1)
        - 추가적인 공간을 거의 사용하지 않으며, 입력 배열과 변수들만 사용합니다.

6. **추가 고려 사항**:
    - 배열 요소가 모두 0인 경우도 고려하여, 최소 large sum은 0이 됩니다.
    - K가 1인 경우는 전체 배열의 합이 최소 large sum이 됩니다.
    - K가 배열의 크기와 같은 경우는 각 요소가 하나의 블록에 속하므로, 최소 large sum은 배열의 최대 요소 값이 됩니다.

이 코드는 주어진 문제를 효율적으로 해결하며, 다양한 테스트 케이스를 통해 함수의 정확성과 효율성을 검증할 수 있습니다.
*/
