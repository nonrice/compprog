n = int(input())

adj = [[] for _ in range(n+1)]
for _ in range(0, n-1):
    u, v = [int(x) for x in input().split()]
    adj[u].append(v)
    adj[v].append(u)

ans = []
rem = n
gone = [False for _ in range(n+1)]
for u in range(1, n+1):
    if len(adj[u]) > 2:
        rem -= (not gone[u])
        gone[u] = True
        for v in adj[u]:
            rem -= (not gone[v])
            gone[v] = True
        ans.append(len(adj[u]))

ans.sort()
print("2 " * (rem//3), end="")
for sz in ans: print(sz, end=" ")

