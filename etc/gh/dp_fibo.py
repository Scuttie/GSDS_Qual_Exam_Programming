def fibonacci(n):
    dp = [0] * (n + 1)
    dp[0] = 0
    dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

n = int(input("n을 입력하세요: "))
print(f"피보나치 수열의 {n}번째 수: {fibonacci(n)}")
