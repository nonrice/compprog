from itertools import permutations

x = 6

for a in permutations(range(1, x+1), x):
    good = True
    for l in range(0, x):
        s = a[l]
        for r in range(l+1, x):
            s += a[r]
            if s 
