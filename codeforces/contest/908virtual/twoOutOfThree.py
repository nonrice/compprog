for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [1] * n

    p1 = 0
    for i in range(0, n):
        for j in range(i+1, n):
            if a[i] == a[j]:
                b[j] = 2
                p1 = a[j]
                break
        else:
            continue
        break
    else:
        print("-1")
        continue

    for i in range(0, n):
        for j in range(i+1, n):
            if a[i] == a[j] and a[j] != p1:
                b[j] = 3
                break
        else:
            continue
        break
    else:
        print("-1")
        continue

    print(*b)
