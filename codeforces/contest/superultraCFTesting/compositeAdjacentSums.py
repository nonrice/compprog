for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    
    for i in range(1, n-1):
        if a[i] == -1:
            a[i] = abs(a[i-1]*a[i+1])
    print(*a)

