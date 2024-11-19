n = int(input())
s = [list(map(int, input().split())) for _ in range(n)]

a = []
def check(c):
    ans = 0
    global a
    a = [0]*n
    a[0] = c
    for i in range(1, n):
        a[i] = min(max(a[i-1], s[i][0]), s[i][1])
        ans += abs(a[i]-a[i-1])
    return ans

l = s[0][0]
r = s[0][1]
while l<r:
    m = (l+r)//2
    if check(m) <= check(m+1):
        r = m
    else:
        l = m+1

check(l)
for i in range(n-2, -1, -1):
    if a[i] > a[i+1]:
        a[i] = max(a[i+1], s[i][0])
print(*a)
