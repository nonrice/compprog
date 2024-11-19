import sys

def calc_dist(x1, y1, x2, y2):
    return abs(x1-x2) + abs(y1-y2)

def solve(n, m):
    cells = [(c//m+1, c%m+1) for c in range(n*m)]
    cells.sort(key = lambda c:calc_dist(c[1], c[0], (m+1)/2, (n+1)/2))
    for c in cells:
        print(max(
            calc_dist(c[1], c[0], 1, 1),
            calc_dist(c[1], c[0], m, 1),
            calc_dist(c[1], c[0], m, n),
            calc_dist(c[1], c[0], 1, n)
        ), end=" ")
    print()

cases = int(sys.stdin.readline())
for _ in range(cases):
    header = [int(x) for x in sys.stdin.readline().split()]
    solve(header[0], header[1])

