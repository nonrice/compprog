for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    a = sorted([int(x) for x in input().split()]
    print(sum(a[0:k]) + (n-k)*a[k-1]) 
