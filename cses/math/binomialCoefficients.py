MOD = 1000000007
MX = 1000000

f = [x for x in range(1, MX+1)]
for i in range(1, MX): f[i] = f[i-1]*f[i] % MOD
invf = [0] * MX
for i in range(0, MX): invf[i] = pow(f[i], MOD-2, MOD)

for _ in range(int(input())):
    a, b = [int(x) for x in input().split()]
    a -= 1
    b -= 1
    print(f[a] * invf[b] % MOD * invf[a-b-1] % MOD)

