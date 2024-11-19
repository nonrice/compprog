from sys import setrecursionlimit
setrecursionlimit(200000)

n = int(input())
adj = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

ans = 0
def dfs(u, p, d):
    if len(adj[u]) == 1 and u != 1:
        return 0

    h = [0]
    for v in adj[u]:
        if v != p:
            h.append(dfs(v, u, d+1)+1)
    c = max(h)
    h.append(d)
    h.sort(reverse=True)

    global ans
    ans = max(ans, h[0]+h[1])

    return c 

dfs(1, -1, 0)
print(ans)
