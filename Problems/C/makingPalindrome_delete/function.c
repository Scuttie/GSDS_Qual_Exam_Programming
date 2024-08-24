#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

// 풀라다가 복잡해서 GPT가 짜줌 확인 해야함
// DP 기반 회문 생성 함수 - 추가 없이 오직 제거만 수행
int makingPalindrome(const char* s, char* result) {
    int n = strlen(s);
    int dp[n][n];

    // DP 테이블 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // DP 테이블 채우기
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            // 양 끝 문자가 같은 경우, 중간 부분의 dp 값을 가져옴
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];  // 양 끝이 같으면 제거할 필요 없음
            } 
            // 양 끝 문자가 다른 경우, 최소 제거 횟수를 계산
            else {
                // 두 가지 선택지 중 더 적은 제거 횟수를 선택
                if (dp[i + 1][j] < dp[i][j - 1]) {
                    dp[i][j] = 1 + dp[i + 1][j];  // s[i]를 제거한 경우
                } else {
                    dp[i][j] = 1 + dp[i][j - 1];  // s[j]를 제거한 경우
                }
            }
        }
    }
    
    // 회문 결과를 위한 배열 생성
    int left = 0, right = n - 1;
    int l = 0, r = n - 1 - dp[0][n - 1];
    char palindrome[r + 2];
    palindrome[r + 1] = '\0';

    // DP 테이블을 이용해 최적 경로 추적 및 회문 생성 - 문자를 추가하지 않고 제거만 수행
    while (left <= right) {
        if (s[left] == s[right]) {
            palindrome[l] = s[left];
            palindrome[r] = s[right];
            left++;
            right--;
            l++;
            r--;
        } else if (dp[left + 1][right] < dp[left][right - 1]) {
            left++;  // 왼쪽 문자 제거
        } else {
            right--;  // 오른쪽 문자 제거
        }
    }

    // 결과 저장
    strcpy(result, palindrome);

    // 제거한 문자의 개수를 반환
    return dp[0][n - 1];
}
