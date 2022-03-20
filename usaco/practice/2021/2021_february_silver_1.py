import sys

def find_empty(cow, needed, graph):
    x = cow[0]
    y = cow[1]
    empty = []
    
    for neighbor in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
        if neighbor not in needed and neighbor not in graph:
            empty.append(neighbor)
    
    return empty

def find_neighbors(cow, needed, graph):
    x = cow[0]
    y = cow[1]
    neighbors = []
    
    for neighbor in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
        if neighbor in needed or neighbor in graph:
            neighbors.append(neighbor)
    
    return neighbors

def dfs_notrecursive(cow, graph, needed):
    to_visit = [cow]
    
    while len(to_visit) > 0:
        to_visit_new = []
        for cow in to_visit:
            empty = find_empty(cow, needed, graph)
            neighbors = find_neighbors(cow, needed, graph)

            if len(empty) == 1:
                needed.add(empty[0])
                to_visit_new.append(empty[0])

            for neighbor in neighbors:
                empty = find_empty(neighbor, needed, graph)
                if len(empty) == 1:
                    needed.add(empty[0])
                    to_visit_new.append(empty[0])
            
        to_visit = to_visit_new

    return needed

def dfs(cow, graph, needed):
    return dfs_notrecursive(cow, graph, needed)

occupied = set()
n = int(sys.stdin.readline())
prev_needed = set()

for x in range(n):
    cow = tuple([int(x) for x in sys.stdin.readline().split()])
    occupied.add(cow)
    
    if cow in prev_needed:
        prev_needed.remove(cow)
    else:
        prev_needed = dfs(cow, occupied, prev_needed)

    print(len(prev_needed))
