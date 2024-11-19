n, m, k = map(int, input().split())

dp = [[[0 for _ in range(k+1)] for _ in range(m+1)] for _ in range(n+1)]
dp[0][0][0] = 1 
for i in range(0, n+1):
    for j in range(0, m+1):
        for k in range(0, k+1):
            if i>0:
                dp[i][j][k] += dp[i-1][j][k]
            if j>0:
                dp[i][j][k] += dp[i][j-1][k]
            if k>0 and i>0 and j>0:
                dp[i][j][k] += dp[i-1][j-1][k-1]

print(sum(dp[n][m]))
