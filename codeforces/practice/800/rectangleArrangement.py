def solve():
    n = int(input())
    mw, mh = 0, 0
    for _ in range(n):
        w, h = map(int, input().split())
        mw = max(mw, w)
        mh = max(mh, h)

    print(2*mw + 2*mh)

for _ in range(int(input())):
    solve()
