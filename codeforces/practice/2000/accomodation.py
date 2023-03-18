n, m = [int(x) for x in input().split()]

ans1 = 0
ans2 = 0
for _ in range(n):
    s = input()
    dp1 = [0] * (m+1)
    dp2 = [0] * (m+1)
    for i in range(2, m+1):
        if s[i-1]=='1' and s[i-2]=='1':
            dp1[i] = dp1[i-2]+1
            dp2[i] = dp2[i-1]
        else:
            dp1[i] = dp1[i-1]
            dp2[i] = dp2[i-2]+1

    ans1 += s.count('1') - min(m//4, dp1[m])
    ans2 += s.count('1') - max(0, m//4 - dp2[m])

print(ans1, ans2)

