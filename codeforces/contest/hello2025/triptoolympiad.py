for _ in range(int(input())):
    a, b, c = map(int, input().split())
    print((a^b) + (b^c) + (a^c));