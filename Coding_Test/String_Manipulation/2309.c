#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10

// dp[i][j] : 문자열의 i번째부터 j번째까지 부분 중에서 만들 수 있는
//            가장 긴 팰린드롬 부분수열의 길이
static int dp[MAX_LEN+1][MAX_LEN+1];

// choice[i][j] : dp[i][j]를 만들 때 어떤 선택을 했는지 기록하여
//                팰린드롬 복원을 쉽게 하기 위한 배열
//   - 0 : s[i] == s[j] 를 사용 (양쪽 문자를 포함)
//   - 1 : i를 버리고 (i+1, j)에서 찾아감
//   - 2 : j를 버리고 (i, j-1)에서 찾아감
static int choice[MAX_LEN+1][MAX_LEN+1];

// 문자열 s에서 dp와 choice 배열을 채우는 함수
void calcLPS(const char *s, int n) {
    // 길이가 1인 부분 문자열은 모두 팰린드롬이므로 길이는 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        choice[i][i] = 0;  // 자기 자신만 있으므로 0으로 통일(크게 상관 없음)
    }

    // 부분 문자열의 길이(2 이상) 차례대로 확인
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i + length - 1 < n; i++) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                if (length == 2) {
                    // 길이 2, 양 끝이 같으면 팰린드롬 길이는 2
                    dp[i][j] = 2;
                } else {
                    // 양 끝 문자가 같은 경우
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                choice[i][j] = 0; // 양쪽 문자를 사용
            } else {
                // 양 끝 문자가 다른 경우, 하나를 버리고 최대값 선택
                if (dp[i+1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i+1][j];
                    choice[i][j] = 1; // i를 버림
                } else {
                    dp[i][j] = dp[i][j-1];
                    choice[i][j] = 2; // j를 버림
                }
            }
        }
    }
}

// choice 배열을 이용하여 팰린드롬을 실제로 복원하는 함수
void buildPalindrome(const char *s, int i, int j, char *result) {
    // 팰린드롬의 최종 길이
    int length = dp[i][j];
    // 복원할 때, 왼쪽/오른쪽에서 채워넣을 인덱스
    int left = 0;
    int right = length - 1;

    // i <= j 범위 안에서 팰린드롬을 재구성
    while (i <= j) {
        if (i == j) {
            // 홀수 길이 팰린드롬의 가운데 문자
            result[left] = s[i];
            break;
        }
        // choice 에 따른 분기
        if (choice[i][j] == 0) {
            // 양끝 문자 사용
            result[left] = s[i];
            result[right] = s[j];
            left++;
            right--;
            i++;
            j--;
        } else if (choice[i][j] == 1) {
            // i 버림
            i++;
        } else { // choice[i][j] == 2
            // j 버림
            j--;
        }
    }
    // 문자열 끝에 null 추가
    result[length] = '\0';
}

int main(void) {
    char s[MAX_LEN+1];
    // 문자열 입력
    scanf("%s", s);

    int n = (int)strlen(s);

    // dp, choice 배열 0으로 초기화
    memset(dp, 0, sizeof(dp));
    memset(choice, 0, sizeof(choice));

    // dp 계산
    calcLPS(s, n);

    // LPS 길이
    int lps_len = dp[0][n-1];
    // 제거한 문자의 개수
    int remove_cnt = n - lps_len;

    // 복원할 팰린드롬을 저장할 배열
    char palindrome[MAX_LEN+1];
    memset(palindrome, 0, sizeof(palindrome));

    buildPalindrome(s, 0, n-1, palindrome);

    // 결과 출력
    printf("%d\n", remove_cnt);
    printf("%s\n", palindrome);

    return 0;
}
