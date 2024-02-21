M = 998244353

def solve():
    n, k = map(int, input().split())

    dp = [[1]*(k+1)] + [[0 for _ in range(k+1)] for _ in range(n)]
    for i in range(1, n+1):
        for j in range(0, k+1):
            for l in range(0, k-j):
                if i-(l+1)*(j+1) < 0:
                    break
                dp[i][j] = (dp[i][j] + dp[i-(l+1)*(j+1)][l]) % M

    ans = 0
    for j in range(0, k+1):
        ans = (ans + dp[n][j]) % M
    print(ans)

for _ in range(int(input())):
    solve()

