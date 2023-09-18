for _ in range(int(input())):
    n = int(input())
    b = [int(x) for x in input().split()]

    if n == 1:
        print("YES")
        print(b[0])
        continue

    nnum = (-2-n)*(n-1)//2
    pnum = n*(n+1)//2 + 1
    den = n*n*(n+1)//2

    ans = [0] * n
    mid = sum(b[1:n-1])
    for l in range(0, n):
        total = b[l]*nnum + mid + b[(l+n-1)%n]*pnum
        
        if total % den or total//den <= 0 or total//den > 1000000000:
            print("NO")
            break

        ans[l] = total//den
        mid += b[(l+n-1)%n] - b[(l+1)%n]
    else:
        print("YES")
        for x in ans: print(x, end=" ")
        print()
