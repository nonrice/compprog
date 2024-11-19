for _ in range(int(input())):
    n = int(int(input()))
    ans = 0
    for i in range(0, n):
        a = list(range(1, i+1)) + list(reversed(list(range(i+1, n+1))))
        b = [(i+1)*a[i] for i in range(len(a))]
        ans = max(ans, sum(b)-max(b))
    print(ans)

