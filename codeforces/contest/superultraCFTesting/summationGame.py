for _ in range(int(input())):
    n, k, x = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()] + [0]

    a.sort(reverse=True)
    w = sum(a[:x])
    t = sum(a[x:])
    ans = t-w
    for i in range(x, x+k):
        w += a[min(i, n)]-a[i-x]
        t -= a[min(i, n)]
        ans = max(ans, t-w)

    print(ans)
