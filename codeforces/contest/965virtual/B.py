def solve():
    n = int(input())
    a = list(map(int, input().split()))

    print(*(a[-1:] + a[:-1]))
    

for _ in range(int(input())):
    solve()
