MOD = 998244353

n = int(input())
A = list(map(int, input().split()))

o, e, ee, eo, oe, oo = 0, 0, 0, 0, 0, 0

ans = 0
for a in A:
    if a%2:
        ans = ((ans+eo) % MOD + oe) % MOD
        oo = ((oo + eo) % MOD + o) % MOD
        eo = ((eo + oe) % MOD + e) % MOD
        o += 1
    else:
        ans = ((ans+ee) % MOD + oo) % MOD
        ee = ((ee + ee) % MOD + e) % MOD
        oe = ((oe + oo) % MOD + o) % MOD
        e += 1

print(ans)
