n, q = [int(x) for x in input().split()]

a = [int(x) for x in input().split()]

b = [False] * n
b[0] = True 

for i in range(1, n):
    if a[i] > a[i-1]:
        b[i] = True
        b[i-1] = True


p = [0] * (n+1)
for i in range(1, n+1):
    p[i] = p[i-1] + b[i-1]

for _ in range(q):
    l, r = [int(x) for x in input().split()]
    increase = (1 if b[r-1]==False else 0) + (1 if b[l-1]==False else 0)
    if increase==2 and r==l: increase -= 1
    print(p[r] - p[l-1] + increase)
