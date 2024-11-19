from math import gcd

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    ans = abs(a[n-1] - a[0])
    for i in range(0, n//2 + 1):
        ans = gcd(ans, abs(a[n-i-1] - a[i]))

    print(ans)

