n = int(input())
a = [int(x) for x in input().split()]

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]

for l in range(n, -1, -1):
    for r in range(0, n+1):
        if l < r:
            if (r-l)%2 == n%2:
                dp[l][r] = max(dp[l+1][r]+a[l], dp[l][r-1]+a[r-1])
            else:
                dp[l][r] = min(dp[l+1][r]-a[l], dp[l][r-1]-a[r-1])

print(dp[0][n])

