for _ in range(int(input())):
    n = int(input())
    if n%2 == 0:
        print("-1")
        continue

    for i in range(n, -1, -2):
        print(i, end=" ")
    for i in range(2, n+1, 2):
        print(i, end=" ")
    print()
