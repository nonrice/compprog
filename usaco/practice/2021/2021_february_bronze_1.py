import sys
count = int(sys.stdin.readline()[:-1])
commands = []
for i in range(count):
    commands.append(sys.stdin.readline()[:-1].split())

def find_neighbors(commands, name):
    neighbors = []
    for i in range(len(commands)):
        if commands[i][7] == name:
            neighbors.append(i)
    return neighbors

def parse_command(direction, target_year, cur_year, year_offset):
    if direction == "previous":
        if animals[target_year] >= animals[cur_year]:
            year_offset -= 12 - (animals[target_year] - animals[cur_year])
        else:
            year_offset -= animals[cur_year] - animals[target_year]
    else:
        if animals[cur_year] >= animals[target_year]:
            year_offset += 12 - (animals[cur_year] - animals[target_year])
        else:
            year_offset += animals[target_year] - animals[cur_year]
    
    return year_offset, target_year

def dfs_recursive(v, visited, path):
    visited.add(v)
    path.append(v)
    for neighbour in find_neighbors(commands, commands[v][0]):
        if neighbour not in visited:
            dfs_recursive(neighbour, visited, path)
    
    if commands[v][0] == "Elsie":
        year_offset = 0
        cur_year = "Ox"
        for x in path:
            year_offset, cur_year = parse_command(commands[x][3], commands[x][4], cur_year, year_offset)
        print(abs(year_offset))

    path.pop()

def dfs():
    visited = set()
    path = []
    for neighbour in find_neighbors(commands, "Bessie"):
        dfs_recursive(neighbour, visited, path)


animals = {
    "Ox": 0,
    "Tiger": 1,
    "Rabbit": 2,
    "Dragon": 3,
    "Snake": 4,
    "Horse": 5,
    "Goat": 6,
    "Monkey": 7,
    "Rooster": 8,
    "Dog": 9, 
    "Pig": 10,
    "Rat": 11
}

dfs()
