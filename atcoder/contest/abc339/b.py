h, w, n = map(int, input().split())

g = [["." for _ in range(w)] for _ in range(h)]

x, y = 0, 0
d = [[0, -1], [1, 0], [0, 1], [-1, 0]]
p = 0
for _ in range(n):
    if g[y][x] == '.':
        g[y][x] = '#'
        p = (p+1) % 4
    else:
        g[y][x] = '.'
        p = (p-1) % 4
    x = (x+d[p][0]) % w
    y = (y+d[p][1]) % h

for r in g:
    print("".join(r))

