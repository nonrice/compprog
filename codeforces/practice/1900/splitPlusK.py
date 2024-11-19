from math import gcd

for _ in range(int(input())):
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    d = A[0] - k;
    for a in A:
        d = gcd(d, a-k)
    if any([a-k<0 for a in A]):
        d *= -1
    if d == 0:
        print("0")
        continue

    Q = list(map(lambda a : (a-k)//d - 1, A))
    if any([q<0 for q in Q]):
        print("-1")
        continue
    print(max(-1, sum(Q)))



