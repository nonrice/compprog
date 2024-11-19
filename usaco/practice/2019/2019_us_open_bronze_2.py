f = open("factory.in")
neighbors = {}
factories = set()
count = int(f.readline())

for x in range(count-1):
    conveyor = [int(x) for x in f.readline().split()]
    factories.add(conveyor[0])
    factories.add(conveyor[1])
    if conveyor[1] in neighbors:
        neighbors[conveyor[1]].add(conveyor[0])
    else:
        neighbors[conveyor[1]] = set([conveyor[0]])

def dfs_recursive(node, neighbors, visited):
    visited.add(node)
    if node in neighbors:
        for neighbor in neighbors[node]:
            if neighbor not in visited:
                dfs_recursive(neighbor, neighbors, visited)

def dfs(node, neighbors):
    visited = set()
    dfs_recursive(node, neighbors, visited)
    return visited


min_i = 99999

for x in neighbors:
    if dfs(x, neighbors) == factories:
        if x < min_i:
            min_i = x

f = open("factory.out", "w")

if min_i == 99999:
    f.write("-1")
else:
    f.write(str(min_i))

f.close()