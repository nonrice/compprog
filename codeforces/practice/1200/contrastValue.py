import sys

for _ in range(int(sys.stdin.readline()[:-1])):
    n = int(sys.stdin.readline()[:-1])
    a = [int(x) for x in sys.stdin.readline()[:-1].split()]

    up = False
    for i in range(1, len(a)):
        if a[i] > a[0]:
            up = True
            break
        if a[i] < a[0]:
            break
    else:
        print(1)
        continue

    ans = 2
    for i in range(1, len(a)):
        if a[i] > a[i-1] and up == False:
            up = True
            ans += 1
        elif a[i] < a[i-1] and up:
            up = False
            ans += 1

    print(ans)

