n = int(input())
a = list(map(int, input().split()))

D = 0
m = float("inf")
for d in a:
    D += d
    m = min(m, D)

print(abs(min(m, 0)) + D)
