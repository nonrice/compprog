M = 1000000007

for _ in range(int(input())):
    d = int(input())

    ans = 0
    n = (pow(2, d, M) - 1) % M
    for h in range(0, d-1):
        p2h1 = (pow(2, h+1, M) - 1)%M

        #print(n-p2h1, p2h1, pow(2, d-h-1, M))

        ans = (ans + (n - p2h1)%M * p2h1%M * pow(2, d-h-1, M)%M * 2%M) % M

    print(ans)
        
