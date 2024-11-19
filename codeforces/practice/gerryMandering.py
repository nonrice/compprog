def get_vote(a, b, c):
    return ((a=='A') + (b=='A') + (c=='A')) >= 2

def solve():
    n = int(input())
    a = [input(), input()]

    dp = [[0 for _ in range(7)] for _ in range(n+1)]
    # xxxxixxxx
    # x0123456x

    for i in range(0, n+1):
        if i-3 >= 0:
            dp[i][0] = dp[i-3][3] + get_vote(a[0][i-2], a[0][i-1], a[0][i])
        if i-2 >= 0:
            dp[i][1] = dp[i-3][4] + get_vote(a[0][i-2], a[0][i-1], a[0][i])
        if i-1 >= 0:
            dp[i][1] = max(
                dp[i-3][5] + get_vote(a[0][i-2], a[0][i-1], a[0][i]),
                dp[i-2][3] + get_vote(a[0][i-1], a[0][i], a[1][i-1])
            )
            

for _ in range(int(input())):
    solve()
