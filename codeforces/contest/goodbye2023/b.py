from math import gcd

for _ in range(int(input())):
    a, b = map(int, input().split())

    if a == 1:
        print(b*b)
    elif b % a:
        print(a*b//gcd(a, b))
    else:
        print(b*(b//a))

