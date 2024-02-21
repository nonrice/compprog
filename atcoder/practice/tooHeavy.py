n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
P = list(map(lambda t : int(t)-1, input().split()))

S = list(range(0, n))
S.sort(key = lambda x : B[x])
O = [0]*n
for i, p in enumerate(P):
    O[p] = i

ans = []
i = 0
while i<n:
    u, v = O[S[i]], O[O[S[i]]]
    if u != v:
        if A[u] <= B[P[u]] or A[v] <= B[P[v]]:
            print("-1")
            exit(0)
        ans.append((u, v))
        O[P[u]], O[P[v]] = O[P[v]], O[P[u]]
        P[u], P[v] = P[v], P[u]
    else:
        i += 1

print(len(ans))
for u, v in ans:
    print(u+1, v+1)
