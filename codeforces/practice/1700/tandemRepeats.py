for _ in range(int(input())):
    s = input()
    n = len(s)
    ans = 0
    for k in range(n):
        l = 0
        for i in range(n-k):
            if s[i]==s[i+k] or s[i]=='?' or s[i+k]=='?':
                l += 1
            else:
                l = 0
            if l == k:
                ans = 2*k
    print(ans)
