def solve():
    n, k = map(int, input().split())
    s = list(input())

    if k>=n:
        print("-1")
        return

    w = s[0:k].count('#')
    m = w
    for i in range(1, n+1-k):
        w -= (s[i-1] == '#')
        w += (s[i-1+k] == '#')
        m = min(m, w)
    print(m+1)
        

for _ in range(int(input())):
    solve()
                

    
