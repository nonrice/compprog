f = open("breedflip.in")

n = int(f.readline()[:-1])
a = list(f.readline()[:-1])
b = list(f.readline()[:-1])

flips = 0
within_segment = False
for i in range(n):
    if a[i] != b[i] and not within_segment:
        flips += 1
        within_segment = True
    elif a[i] == b[i]:
        within_segment = False

f = open("breedflip.out", "w")
f.write(str(flips))
f.close()
