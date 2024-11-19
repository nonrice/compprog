for _ in range(int(input())):
    x, y, k = map(int, input().split())

    if k % 2:
        print(x, y)
    for i in range(1, k, 2):
        print(x, y+i)
        print(x, y-i)
