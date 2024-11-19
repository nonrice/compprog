for _ in range(int(input())):
    n, x, y = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    ans = x-2
    for i in range(x):
        d = (n + a[i]-a[i-1 if i>=1 else i-1+x]) % n
        if d == 2:
            ans += 1
        elif d > 2:
            ans +=  
            y -= 1
    print(ans)
