from queue import PriorityQueue

INF = 1000000001

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
    adj[v].append((u, w))
s, f = map(int, input().split())

dist = [INF] * (n+1)
vis = [False] * (n+1)
dist[s] = 0
pq = PriorityQueue()
pq.put((0, s))
while not pq.empty():
    d, u = pq.get()
    vis[u] = True
    for v, w in adj[u]:
        if not vis[v] and dist[v] > d+w:
            dist[v] = d+w
            pq.put((d+w, v))

if dist[f] == INF:
    print("-1")
else:
    print(dist[f])


