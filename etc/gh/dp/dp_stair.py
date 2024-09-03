def climbStairs(n):
    if n == 1:
        return 1
    dp = [0] * (n + 1)
    dp[1] = 1
    dp[2] = 2

    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

n = int(input("계단의 수를 입력하세요: "))
print(f"계단을 오르는 방법의 수: {climbStairs(n)}")
