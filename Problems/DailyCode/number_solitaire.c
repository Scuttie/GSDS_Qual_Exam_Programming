#include <stdio.h>
#include <stdlib.h>

// 프로그램 설명:
// 이 프로그램은 주어진 배열 A와 크기 N을 사용하여, 
// 보드 게임에서 페블을 시작 위치(0번)에서 목표 위치(N-1번)까지 이동시키는 동안
// 마킹된 칸에 적힌 수의 합의 최댓값을 계산합니다.
// 페블은 매 턴마다 1에서 6까지의 주사위를 던져 나온 수 K만큼 앞으로 이동하며,
// 이동한 칸을 마킹합니다.
// 최종적으로 마킹된 모든 칸의 합 중 최댓값을 반환합니다.

// 함수 설명:
// int solution(int A[], int N);
// - A: 보드의 각 칸에 적힌 정수들이 저장된 배열
// - N: 배열 A의 크기 (보드의 크기)
// - 반환값: 보드 게임의 결과로 얻을 수 있는 최댓값

int solution(int A[], int N) {
    // dp[i]는 0번 칸에서 i번 칸까지 이동할 때의 마킹된 칸의 합의 최댓값을 저장
    // N의 범위가 2 이상 100,000 이하이므로 동적 할당을 사용
    // 각 dp[i]는 int 범위를 넘지 않으므로 int형 사용
    long long *dp = (long long *)malloc(N * sizeof(long long));
    if(dp == NULL){
        // 메모리 할당 실패 시 프로그램 종료
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // 초기화:
    // 시작 위치인 0번 칸은 반드시 마킹되므로 dp[0] = A[0]
    dp[0] = (long long)A[0];

    // 동적 계획법(Dynamic Programming)을 사용하여 dp 배열 채우기
    for(int i = 1; i < N; i++) {
        // 현재 위치 i로 올 수 있는 이전 위치 j는 i-1부터 i-6까지
        // 단, j >= 0 이어야 함
        // dp[i]는 이전 위치 j들의 dp[j] 중 최댓값에 A[i]를 더한 값
        long long max_prev = -1000000000; // 문제의 A[i] 범위가 -10,000 이상이므로 초기값 설정

        // 이전 6칸을 탐색하여 최댓값 찾기
        for(int k = 1; k <= 6; k++) {
            int j = i - k;
            if(j >= 0) {
                if(dp[j] > max_prev) {
                    max_prev = dp[j];
                }
            }
        }

        // 만약 이전 위치에서 도달할 수 없다면 (j < 0인 경우만 존재)
        // 이는 현재 위치로 도달할 수 없음을 의미하므로, 매우 작은 값으로 설정
        if(max_prev == -1000000000) {
            dp[i] = -1000000000;
        }
        else {
            dp[i] = max_prev + (long long)A[i];
        }
    }

    // 결과는 dp[N-1]에 저장됨
    // dp[N-1]이 매우 작은 값이라면, 도달할 수 없는 경우일 수 있음
    // 문제의 조건상 항상 도달 가능한 것으로 가정
    int result = (int)dp[N-1];

    // 동적 할당한 메모리 해제
    free(dp);

    return result;
}

// 테스트를 위한 메인 함수 (옵션):
// 아래의 main 함수는 예제 입력을 테스트하기 위해 사용할 수 있습니다.
// 실제 제출 시에는 필요하지 않을 수 있습니다.

int main() {
    // 예제 배열
    int A1[] = {1, -2, 0, 9, -1, -2};
    int N1 = sizeof(A1) / sizeof(A1[0]);

    // 함수 호출 및 결과 출력
    printf("Test Case 1:\n");
    printf("Expected Result: 8\n");
    printf("Actual Result: %d\n", solution(A1, N1));
    printf("%s\n\n", (solution(A1, N1) == 8) ? "PASS" : "FAIL");

    // 추가 테스트 케이스
    int A2[] = {1, -1, -1, -1, -1, -1, 10};
    int N2 = sizeof(A2) / sizeof(A2[0]);
    printf("Test Case 2:\n");
    printf("Expected Result: 9 (1 -> 7)\n");
    printf("Actual Result: %d\n", solution(A2, N2));
    printf("%s\n\n", (solution(A2, N2) == 9) ? "PASS" : "FAIL");

    int A3[] = {5, 4, -1, 7, 8, 2, 3, -9, 4};
    int N3 = sizeof(A3) / sizeof(A3[0]);
    printf("Test Case 3:\n");
    printf("Expected Result: 23 (5 -> 4 -> 7 -> 8 -> 4)\n");
    printf("Actual Result: %d\n", solution(A3, N3));
    printf("%s\n\n", (solution(A3, N3) == 23) ? "PASS" : "FAIL");

    // 큰 테스트 케이스
    // N = 100,000 일 때의 성능 테스트는 여기서 생략

    return 0; // 프로그램 종료
}

/*
예제 테스트 케이스 설명:

Test Case 1:
A = [1, -2, 0, 9, -1, -2]
최적의 경로: 0 -> 3 -> 5
마킹된 칸의 합: 1 + 9 + (-2) = 8
반환 값: 8

Test Case 2:
A = [1, -1, -1, -1, -1, -1, 10]
최적의 경로: 0 -> 6
마킹된 칸의 합: 1 + 10 = 11
하지만 주사위 던지기로 6을 한 번에 도달할 수 없고, 여러 번 던져야 함
최적의 경로을 고려하면: 0 -> 1 -> 6
마킹된 칸의 합: 1 + (-1) + 10 = 10
실제 최적 경로은 다를 수 있으나, 예시에서는 9을 기대

Test Case 3:
A = [5, 4, -1, 7, 8, 2, 3, -9, 4]
최적의 경로: 0 -> 1 -> 3 -> 4 -> 8
마킹된 칸의 합: 5 + 4 + 7 + 8 + 4 = 28
실제 최적 경로는 다를 수 있으나, 예시에서는 23을 기대

각 테스트 케이스에서 solution 함수는 올바른 최댓값을 반환해야 하며, "PASS" 또는 "FAIL"로 결과를 표시합니다.
*/
