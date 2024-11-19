for _ in range(int(input())):
    n, h, d, s, p = map(int, input().split())

    if p >= h:
        if p*d/s > n:
            print("-1.0")
        else:
            print(d/s)
    else:
        print(max(0, ((p*d)/s - n)/(h-p)) + d/s)
