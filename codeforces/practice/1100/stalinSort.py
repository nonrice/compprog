def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ans = 1000000
    for i in range(n):
        r = 0
        for j in range(i+1, n):
            r += a[j] > a[i]
        ans = min(ans, i+r)

    print(ans)


for _ in range(int(input())):
    solve()
