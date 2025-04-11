from collections import deque
import random
import time

n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = (int(x) for x in input().split())
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)
uesles = int(input())
classes = [int(x) - 1 for x in input().split()]
key = set(classes)
random.seed(int(time.time()))
root = classes[random.randint(0, len(classes) - 1)]
taha = []
visited = [0] * n
visited[root] = 1
depth = [0] * n
parent = [0] * n
parent[root] = -1
for sub in adj[root]:
    depth[sub] = 1
    parent[sub] = root
    q = deque([sub])
    visited[sub] = 1
    s = set()
    while q:
        node = q.popleft()
        if node in key:
            s.add(node)
        for a in adj[node]:
            if visited[a] == 0:
                visited[a] = 1
                depth[a] = depth[node] + 1
                parent[a] = node
                q.append(a)
    if len(s) > 0:
        taha.append((sub, s))
if len(taha) > 2:
    print(-1)
elif len(taha) == 2:
    sub1, set1 = taha[0]
    sub2, set2 = taha[1]
    maxclass1 = 0
    maxd1 = 0
    for s in set1:
        if depth[s] >= maxd1:
            maxd1 = depth[s]
            maxclass1 = s
    x = maxclass1
    while parent[x] != -1:
        if x in set1:
            set1.remove(x)
        x = parent[x]
    if len(set1) > 0:
        print(-1)
    else:
        maxclass2 = 0
        maxd2 = 0
        for s in set2:
            if depth[s] >= maxd2:
                maxd2 = depth[s]
                maxclass2 = s
        x = maxclass2
        while parent[x] != -1:
            if x in set2:
                set2.remove(x)
            x = parent[x]
        if len(set2) > 0:
            print(-1)
        else:
            totaldepth = 0
            visited = [0] * n
            visited[parent[maxclass1]] = 1
            visited[maxclass1] = 1
            q = deque([maxclass1])
            maxd12 = 0
            while q:
                node = q.popleft()
                if depth[node] > maxd12:
                    maxd12 = depth[node]
                for a in adj[node]:
                    if visited[a] == 0:
                        visited[a] = 1
                        q.append(a)
            maxd22 = 0
            visited[parent[maxclass2]] = 1
            visited[maxclass2] = 1
            q = deque([maxclass2])
            while q:
                node = q.popleft()
                if depth[node] > maxd22:
                    maxd22 = depth[node]
                for a in adj[node]:
                    if visited[a] == 0:
                        visited[a] = 1
                        q.append(a)
            totaldepth = maxd12 + maxd22
            print(totaldepth)
elif len(taha) == 1:
    sub1, set1 = taha[0]
    maxclass1 = 0
    maxd1 = 0
    for s in set1:
        if depth[s] > maxd1:
            maxd1 = depth[s]
            maxclass1 = s
    x = maxclass1
    while parent[x] != -1:
        if x in set1:
            set1.remove(x)
        x = parent[x]
    if len(set1) > 0:
        print(-1)
    else:
        totaldepth = 0
        visited = [0] * n
        visited[parent[maxclass1]] = 1
        visited[maxclass1] = 1
        q = deque([maxclass1])
        maxd12 = 0
        while q:
            node = q.popleft()
            if depth[node] > maxd12:
                maxd12 = depth[node]
            for a in adj[node]:
                if visited[a] == 0:
                    visited[a] = 1
                    q.append(a)
        totaldepth = maxd12
        visited = [0] * n
        visited[sub1] = 1
        maxd3 = 0
        q = deque([root])
        while q:
            node = q.popleft()
            if depth[node] > maxd3:
                maxd3 = depth[node]
            for a in adj[node]:
                if visited[a] == 0:
                    visited[a] = 1
                    q.append(a)
        totaldepth += maxd3
        print(totaldepth)
