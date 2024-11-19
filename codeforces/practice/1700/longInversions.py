from collections import deque

for _ in range(int(input())):
    n = int(input())
    s = input()
    for k in range(n-1, -1, -1):
        r = deque()
        for i in range(0, n-k):
            if (s[i]=='1') == len(r)%2:
                r.append(i+k)
            if len(r) and i == r[0]:
                r.popleft()
        f = False
        for i in range(n-k, n):
            if (s[i]=='1') == len(r)%2:
                f = True
                break
            if len(r) and i == r[0]:
                r.popleft()
        if not f:
            print(k+1)
            break



