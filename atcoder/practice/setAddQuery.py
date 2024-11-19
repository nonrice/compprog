n, q = map(int, input().split())
x = [0] + list(map(lambda x : int(x)-1, input().split()))
p = [0]*(q+1)
s = dict() 
a = [0]*n
for i in range(1, q+1):
    if x[i] in s:
        a[x[i]] += p[i-1] - p[s[x[i]]-1]
        s.pop(x[i])
    else:
        s[x[i]] = i
    p[i] = p[i-1] + len(s)
for x in s:
    a[x] += p[q] - p[s[x]-1]
print(*a)

