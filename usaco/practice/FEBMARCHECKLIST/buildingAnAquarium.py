def solve():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    h = 0
    s = 1000000000
    while s >= 1:
        while sum(map(lambda v : max(0, h+s-v), a)) <= x:
            h += s
        s //= 2
    print(h)

for _ in range(int(input())):
    solve()
