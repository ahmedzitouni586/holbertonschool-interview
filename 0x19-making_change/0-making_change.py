#!/usr/bin/python3
def makeChange(coins, total):
    if total <= 0:
        return 0
    dp = [float("inf")] * (total + 1)
    dp[0] = 0
    for i in range(1, total + 1):
        for j in range(len(coins)):
            if coins[j] <= i:
                dp[i] = min(dp[i], dp[i - coins[j]] + 1)
    return dp[total] if dp[total] != float("inf") else -1