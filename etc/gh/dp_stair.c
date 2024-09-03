#include <stdio.h>

int climbStairs(int n) {
    if (n == 1) return 1;
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("계단의 수를 입력하세요: ");
    scanf("%d", &n);

    printf("계단을 오르는 방법의 수: %d\n", climbStairs(n));
    return 0;
}
