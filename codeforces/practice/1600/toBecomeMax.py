from sys import setrecursionlimit, stdin
from bisect import bisect_right

setrecursionlimit(1001)

def read_ints():
    return [int(x) for x in stdin.readline()[:-1].split()]

for _ in range(int(input())):
    n, m = read_ints()
    a = read_ints()

    def dp(i, j, k):
        if k < 0:
            return False
        if i == n-1:
            return j <= a[n-1]
        if j <= a[i]:
            return True
        return dp(i+1, j-1, k-(j-a[i]))

    class DP:
        def __init__(self, i, k):
            self.i = i
            self.k = k

        def __getitem__(self, j):
            return not dp(self.i, j, self.k)
    
    ans = 0
    for i in range(0, n):
        ans = max(ans, bisect_right(DP(i, m), False, a[i], a[i]+m+1)-1)

    print(ans)

