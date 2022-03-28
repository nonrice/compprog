import sys

def dfs(node, non_adj, weights, total):
    visited = set(list(non_adj[node]))
    return dfs_recursive(node, visited, non_adj, weights, total)

def dfs_recursive(node, visited, non_adj, weights, total):
    for val in non_adj[node]:
        visited.add(val)
    max_val = weights[node]
    for n in range(1, total+1):
        if n not in non_adj[node] and n not in visited:
            max_val = max(max_val, dfs_recursive(n, visited, non_adj, weights, total)+weights[node])
    return max_val

node_count = int(sys.stdin.readline())
non_adj = {} 
weights = {} 

for n in range(node_count):
    node = [int(x) for x in sys.stdin.readline()[:-1].split()]
    weights[n+1] = node[1]
    non_adj[node[0]] = set([node[0], n+1])

max_val = 0
for n in range(1, node_count+1):
    max_val = max(max_val, dfs(n, non_adj, weights, node_count))

print(max_val)
