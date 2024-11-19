for _ in range(int(input())):
    n = int(input())

    for i in range(0, 2*n):
        for j in range(0, 2*n):
            if (i//2 + j//2) % 2:
                print('.', end="")
            else:
                print('#', end="")
        print()
