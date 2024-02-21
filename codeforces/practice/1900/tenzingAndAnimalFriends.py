from heapq import *

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((w, v))
    adj[v].append((w, u))

ans = []
s = ['1']*(n-1) + ['0']
t = 0
pq = []
for e in adj[n]:
    heappush(pq, e)

is_inf = True 
while len(pq):
    w, u = heappop(pq)
    ans.append((''.join(s), w-t))
    t = w
    s[u-1] = '0'
    if u-1 == 0:
        is_inf = False
        break
    
    for w, v in adj[u]:
        if s[v-1] == '1':
            heappush(pq, (w+t, v))

if is_inf:
    print("inf")
else:
    print(t, len(ans))
    for s, t in ans:
        print(s, t)
