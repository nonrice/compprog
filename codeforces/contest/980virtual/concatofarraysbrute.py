import itertools

for _ in range(int(input())):
    a = [list(map(int, input().split())) for _ in range(int(input()))]

    ans = []
    ans_v = 99999;
    for p in itertools.permutations(a):
        v = 0
        b = [x for t in p for x in t]
        for i in range(len(b)):
            for j in range(i+1, len(b)):
                v += b[i]>b[j]

        if v < ans_v:
            ans = b.copy()
    
    print(*ans)

    