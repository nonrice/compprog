for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))

    o, e = 0, 0
    s = 0
    for a in A:
        if a % 2: o += 1
        else: e += 1
        
        s += a
        
        ans = s-o//3

        if o%3 == 1 and o+e != 1: ans -= 1

        print(ans, end=' ')
    print()

