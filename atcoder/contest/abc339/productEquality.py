from math import gcd

n = int(input())
A = [int(input()) for _ in range(n)]

G = A[0]
for a in A:
    G = gcd(G, a)
for a in A:
    a //= G

f = dict()
for a in A:
    f[a] = f.get(a, 0) + 1

print(A)

ans = 0
for a in A:
    for b in A:
        ans += f.get(a*b, 0)
print(ans)
