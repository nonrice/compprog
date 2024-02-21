import sys

#sys.stdin = open("spainting.in", "r")
#sys.stdout = open("spainting.out", "w")

M = 1000000007

n, m, k = [int(x) for x in input().split()]

p = [1] * (n+1)
for i in range(1, (n+1)):
    p[i] = p[i-1]*m % M

c = 1
for i in range(1, (n+1)):
    c = c*m % M
    if i - k > 0:
        c = (c - p[i-k]*(m-1)%M) % M
    elif i - k == 0:
        c = (c - m) % M

print((p[n] - c) % M)
