import math

# ARBITRARY PRECISION BABY

def big_sqrt(x):
    step = x;
    cur = 0;
    while step >= 1:
        while (cur+step) * (cur+step) <= x:
            cur += step
        step //= 2
    return cur

def solve():
    n = int(input())

    print(math.floor(0 - ((1 - big_sqrt(8*n + 1))/2)))

for _ in range(int(input())):
    solve()
