import sys

MOD = 998244353

n = int(input())
a = [int(x) for x in sys.stdin.readline().split()]

x, y = 0, 0

for i in range(0, n, 3):
    p, q, r = sorted(a[i:i+3])
    if p == q and q == r: y += 1
    elif p == q: x += 1 

fn, fk = 0, 0
f = 1
for cur in range(1, n//3 + 1):
    f = f*cur % MOD
    if cur == n//6: fk = f
    elif cur == n//3: fn = f

print(fn * pow(fk*fk % MOD, MOD-2, MOD) % MOD * pow(2, x, MOD) % MOD * pow(3, y, MOD) % MOD)

