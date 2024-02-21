for _ in range(int(input())):
    l, r = map(int, input().split())

    s = l
    k = 0
    while s <= r:
        k += 1
        s *= 2


