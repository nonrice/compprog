for _ in range(int(input())):
    l, r = map(int, input().split())
    L, R = map(int, input().split())

    print(max(0, r-l+1 + R-L+1 - (max(r, R)-min(l, L)+1)) + 1)
