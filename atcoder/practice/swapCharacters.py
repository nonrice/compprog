M = 998244353
N = 250000

f = [1] * (N+1) 
fi = [1] * (N+1)
for i in range(1, N+1):
    f[i] = f[i-1]*i % M
    fi[i] = pow(f[i], M-2, M)

def binom(n, k):
    return f[n]*fi[k]%M * fi[n-k]%M

def d(a, b, c):
    ans = 0
    for x in range(0, a+1):
        for y in range(0, b+1):
            for z in range(0, c+1):
                ans = (ans + pow(-1, x+y+z)*binom(a, x)%M * binom(b, y)%M * binom(c, z)%M * f[a+b+c-x-y-z]%M * fi[a-x]%M * fi[b-y]%M * fi[c-z]%M) % M
    return ans

n, k = map(int, input().split())
s = input()
A, B, C = s.count('A'), s.count('B'), s.count('C')

ans = 0
for a in range(0, k+2):
    for b in range(0, k-a+2):
        for c in range(0, k-a-b+2):
            if a<=A and b<=B and c<=C:
                ans = (ans + binom(A, a)*binom(B, b)%M * binom(C, c)%M * d(a, b, c)%M) % M

print(ans)
