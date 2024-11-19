from math import isqrt

def ceil_isqrt(x):
    ans = isqrt(x)
    if ans*ans < x: ans += 1
    return ans

gr = [ceil_isqrt(1 + 8*x)//2 for x in range(0, 1000002)]
s = [0] * 1000002
for i in range(1, 1000002):
    s[i] = s[i-1] + i**2

for _ in range(int(input())):
    x = int(input())
    cur = gr[x]
    l, r = x, x
    ans = 0

    while l != 0:
        ans += s[r]-s[l-1]
        l -= cur
        r -= cur-1
        
        if gr[l] != cur-1: l += 1
        if gr[r] != cur-1: r -= 1
        cur -= 1

    print(ans)
