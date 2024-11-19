from itertools import permutations

n = int(input())

a = [int(x) for x in input().split()]
b = sorted(a)

f = [[0 for _ in range(4)] for _ in range(4)]
for x, y in zip(a, b):
    f[x-1][y-1] += 1

ans = 0
for k in range(1, 5):
    for seq in permutations(range(4), k):
        cnt = f[seq[0]][seq[1%k]]
        for i in range(1, k):
            cnt = min(cnt, f[seq[i]][seq[(i+1)%k]])
        for i in range(0, k):
            f[seq[i]][seq[(i+1)%k]] -= cnt
        ans += cnt*(k-1)

print(ans)

