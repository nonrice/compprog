f = open("revegetate.in")
header = [int(x) for x in f.readline()[:-1].split()]
n, m = header[0], header[1]

def process_node(node, seeds, neighbors):
    if node in neighbors:
        neighbor_seeds = [0,0,0,0]
        for neighbor in neighbors[node]:
            if seeds[neighbor-1] != 0:
                neighbor_seeds[seeds[neighbor-1]-1] = 1
        
        for i in range(4):
            if neighbor_seeds[i] == 0:
                return i+1
    return 1

neighbors = {}
for x in range(m):
    pair = [int(x) for x in f.readline()[:-1].split()]
    a, b = pair[0], pair[1]

    if a not in neighbors:
        neighbors[a] = set()
    if b not in neighbors:
        neighbors[b] = set()

    neighbors[a].add(b)
    neighbors[b].add(a)

seeds = [0] * n
for x in range(1, n+1):
    seeds[x-1] = process_node(x, seeds, neighbors)

f = open("revegetate.out", "w")
f.write("".join([str(x) for x in seeds]))
f.close
