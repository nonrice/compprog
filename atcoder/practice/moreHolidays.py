n, m, k = [int(x) for x in input().split()]
s = input()

l = []
r = []
cnt = 0
pre = 0
for ch in s:
    pre += 1
    if ch == 'x':
        l.append(pre)
        pre = 0
pre = 0
for ch in reversed(s):
    pre += 1
    if ch == 'x':
        r.append(pre)
        pre = 0
r.reverse()
r[-1] += s.index('x')

cur = (0 if k == m*len(r) else s.index('x')) + sum(r)*(k//len(r)) + sum(r[0:k%len(r)])
ans = cur
if k < len(l)*m:
    for i in range(0, len(l)):
        cur += r[(k+i)%len(r)]-l[i]
        if k+i+1 == m*len(r):
            ans = max(cur-s.index('x'), ans)
            break
        else:
            ans = max(cur, ans)

print(ans)
    
