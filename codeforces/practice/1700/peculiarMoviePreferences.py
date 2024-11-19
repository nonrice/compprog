def solve():
    n = int(input())
    a = [input() for _ in range(n)]

    p = set()
    for s in a:
        if (
            (len(s) == 1) or
            (len(s) == 2 and (s[1]==s[0] or s[1]+s[0] in p or any([s[1]+s[0]+c in p for c in "abcdefghijklmnopqrstuvwxyz"]))) or
            (len(s) == 3 and (s[2]==s[0] or s[2]+s[1] in p or s[2]+s[1]+s[0] in p))
        ):
            print("YES")
            return 
        p.add(s)

    print("NO")

for _ in range(int(input())):
    solve()
