for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    b = [n-1] * n
    for i in range(n-2, -1, -1):
        b[i] = b[i+1]
        if a[b[i+1]] - (b[i+1]-i) <= a[i]: b[i] = i

    l, r = 0, 2
    ans = a[0] + a[1] + a[b[2]] - b[2] 
    for m in range(1, n-1):
        if l != m-1 and a[l]-(m-1-l) <= a[m-1]:
            l = m-1

        if m == r:
            r = b[m+1]

        ans = max(ans, a[l] + a[m] + a[r] - (r-l))
    
    print(ans)

