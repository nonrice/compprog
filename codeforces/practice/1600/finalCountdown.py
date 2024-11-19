for _ in range(int(input())):
    n = int(input())
    s = list(map(lambda d : ord(d)-ord('0'), input()))
    ans = [0]*n
    d = sum(s)
    c = 0
    for i in range(n-1, -1, -1):
        ans[i] = (d%10 + c%10)%10
        c = c//10 + (d + c%10)//10
        d -= s[i]

    p = False
    if c != 0:
        print(c, end="")
        p = True
    for i in range(0, n):
        if p or ans[i]!=0:
            p = True
            print(ans[i], end="")
    print()
