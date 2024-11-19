M = 1000000007

f = [0] * 200001
fi = [0] * 200001

f[0] = fi[0] = f[1] = fi[1] = 1
for i in range(2, 200001):
    f[i] = f[i-1]*i%M
    fi[i] = pow(f[i], M-2, M)

def ncr(n, r):
    if r == 0: return 1
    return f[n] * (fi[r] * fi[n-r]%M) % M

for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]

    if k == 0:
        print(1)
        continue
    
    b = 0
    for v in range(0, n, 2): b = (b+ ncr(n, v)) % M

    if n%2:
        b += 1
        print(pow(b, k, M))
    else:
        ans = pow(b, k, M)
        m = 1
        g = (pow(2, n, M) - 1)%M
        for _ in range(k):
            ans = (ans + m) % M 
            m = m*(g)%M
        print(ans)


