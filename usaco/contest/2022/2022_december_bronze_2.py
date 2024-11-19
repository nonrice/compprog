import sys
amt = int(sys.stdin.readline())
pref = [int(i) for i in sys.stdin.readline().split()]
cur = [int(i) for i in sys.stdin.readline().split()]

i = 0
operations = 0

while cur != pref:
    i = 0
    while i < len(cur):
        if cur[i] < pref[i]:
            start = i
            max_adj = 10001
            while cur[i] < pref[i]:
                if pref[i] - cur[i] < max_adj:
                    max_adj = pref[i] - cur[i]
                i += 1
                if i == len(cur):
                    break
            for j in range(start, i):
                cur[j] += max_adj

            operations += abs(max_adj)
            continue

        elif cur[i] > pref[i]:
            start = i
            max_adj = -10001
            while cur[i] > pref[i]:
                if pref[i] - cur[i] > max_adj:
                    max_adj = pref[i] - cur[i]
                i += 1
                if i == len(cur):
                    break
            for j in range(start, i):
                cur[j] += max_adj

            operations += abs(max_adj)
            continue

        i += 1

print(operations)