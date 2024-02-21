for _ in range(int(input())):
    m = { 0 : [c for c in "abcdefghijklmnopqrstuvwxyz"]}
    n = int(input())
    A = list(map(int, input().split()))
    s = ['-'] * n
    for i, a in enumerate(A):
        l = m[a].pop()
        s[i] = l
        if a+1 not in m:
            m[a+1] = []
        m[a+1].append(l)
    print("".join(s))

