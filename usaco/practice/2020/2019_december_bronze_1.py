f = open("gymnastics.in")
header = [int(x) for x in f.readline()[:-1].split()]
k, n = header[0], header[1]

pair_counts = {}
for i in range(k):
    cows = [int(x) for x in f.readline()[:-1].split()]
    for p in range(n):
        if cows[p] not in pair_counts:
            pair_counts[cows[p]] = set(cows[p+1:])
        else:
            pair_counts[cows[p]] = pair_counts[cows[p]].intersection(set(cows[p+1:]))

pairs = 0
for key in pair_counts:
    pairs += len(pair_counts[key])

f = open("gymnastics.out", "w")
f.write(str(pairs))
f.close()
