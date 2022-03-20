import sys
amt = int(sys.stdin.readline())
mazes = []
k_v = []
for maze in range(0, amt):
    cur_maze = []
    header = sys.stdin.readline().split()
    k_v.append(int(header[1]))
    for row in range(0, int(header[0])):
        cur_maze.append(sys.stdin.readline().split())
    mazes.append(cur_maze)

def check_columns(maze):
    for i in range(0, len(maze)):
        good_row = False
        for row in maze:
            if maze[i] ==1:
                pass

print(mazes)
print(k_v)

for maze in range(0, len(mazes)):
    if k_v[maze] == 1:
        if mazes[maze][0] == len(mazes[maze]) * ["."]:
            pass