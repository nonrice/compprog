import sys

sys.setrecursionlimit(4005)

n, p, t = input().split()
n = int(n)
p = float(p)
t = int(t)

dp = [[0 for y in range(0, t+1)] for x in range(0, t+1)]

def P(x, y):
    if cache[x][y] != -1: return cache[x][y]
    if y == 0: return (x==0) 
    if x == 0: return pow(1-p, y)
    cache[x][y] = P(x-1, y-1)*p + P(x, y-1)*(1-p)
    return cache[x][y]

for i in range(0, t+1):
    for j in range(0, t+1):
        if j == 0: dp[i][j] = float(i == 0)
        elif i == 0: dp[i][j] = pow(1-p, j)
        else: dp[i][j] = dp[i-1][j-1]*p + dp[i][j-1]*(1-p)

print(sum([dp[i][t]*min(n, i) for i in range(0, t+1)]))

