from collections import deque
n=int(input())
adj=[[] for _ in range(n)]
for _ in range(n-1):
    a, b = (int(x) for x in input().split())
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)
visited=[0]*n
depth=[0]*n
q=deque([0])
while q:
    node=q.popleft()
    visited[node]=1
    for a in adj[node]:
        if visited[a]==0:
            q.append(a)
            visited[a]=1
            depth[a]=depth[node]+1
ind=0
d=depth[0]
for i in range(n):
    if depth[i]>d:
        d=depth[i]
        ind=i
depth=[0]*n
visited=[0]*n
q=deque([ind])
while q:
    node=q.popleft()
    visited[node]=1
    for a in adj[node]:
        if visited[a]==0:
            q.append(a)
            visited[a]=1
            depth[a]=depth[node]+1
print(max(depth))