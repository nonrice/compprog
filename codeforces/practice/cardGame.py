import sys

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in sys.stdin.readline()[:-1].split()]

    dp = [[0, 0] for x in range(n)]

    dp[n-1][1] = max(0, a[n-1])
    for i in range(n-2, -1, -1):
        for p in range(0, 2):
            dp[i][p] = max(p*a[i] + dp[i+1][p], p*a[i] + dp[i+1][not p], dp[i+1][not p])

    print(dp[0][1])
