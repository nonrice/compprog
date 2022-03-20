import sys

def solve(n, t):
    changes = 0
    if n < t:
        prev_t = t
        while t > n:
            prev_t = t
            changes += t%2 + 1
            t //= 2
        changes += prev_t-n-1
    else:
        while t < n:
            changes += n%2 + 1
            n = (n+1)//2
        changes += t-n

    return changes

n = int(sys.stdin.readline())
for _ in range(n):
    ln = [int(x) for x in sys.stdin.readline().split()]
    n, t = ln[0], ln[1]
    print(solve(n, t))

