#include <stdio.h>

int fibonacci(int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("n을 입력하세요: ");
    scanf("%d", &n);

    printf("피보나치 수열의 %d번째 수: %d\n", n, fibonacci(n));
    return 0;
}
