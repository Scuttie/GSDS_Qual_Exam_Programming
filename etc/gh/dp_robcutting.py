def rodCutting(price, n):
    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        max_val = -1
        for j in range(i):
            max_val = max(max_val, price[j] + dp[i - j - 1])
        dp[i] = max_val

    return dp[n]

price = [1, 5, 8, 9, 10, 17, 17, 20]
n = len(price)
print(f"최대 수익: {rodCutting(price, n)}")
