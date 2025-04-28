n = 100 

g = [[0 for _ in range(n)] for _ in range(n)]
for i in range(0, n):
    for j in range(0, i+1):
        if j==0 or j==i:
            g[i][j] = 1
        else:
            g[i][j] = g[i-1][j] ^ g[i-1][j-1]

for i, r in enumerate(g):
    print(str(i+1) + " " + "".join(map(str, r)))
