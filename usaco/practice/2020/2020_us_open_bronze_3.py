
f = open("io/tracing.in")
line1 = f.readline().split()
n = int(line1[0])
h = int(line1[1])
cows = [int(x) for x in list(f.readline()[:-1])]
handshakes = []
for line in (f.readlines() [-h:]):
        handshakes.append([int(x) for x in line[:-1].split()])
handshakes = sorted(handshakes,key=lambda x: (x[0]))

print(n)
print(cows)
print(handshakes)

def simulate(handshakes, p0, n, k):
    cows_shakes = n * [0]
    cows = n * [0]
    cows[p0] = 1
    for h in handshakes:
        if cows[h[2]-1] == 1:
            if cows_shakes[h[2]-1] < k:
                cows[h[1]-1] = 1
                cows_shakes[h[2]-1] += 1
        elif cows[h[1]-1] == 1:
            if cows_shakes[h[1]-1] < k:
                cows[h[2]-1] = 1
                cows_shakes[h[1]-1] += 1
    return cows

k_upper = 0
k_lower = len(cows)
c = 0

for p0 in range(0, len(cows)):
    found_match = 0
    for k in range(0, k_lower):
        #print(simulate(handshakes, p0, n, k), k)
        if simulate(handshakes, p0, n, k) == cows:
            if k < k_lower:
                k_lower = k
            found_match = 1
    for k in range(k_upper, len(handshakes)+3):
        print(simulate(handshakes, p0, n, k), k)
        if simulate(handshakes, p0, n, k) == cows:
            if k > k_upper:
                k_upper = k
            found_match = 1

    c += found_match

print(c, k_lower, k_upper if k_upper <= len(cows) else "Infinity")

f = open("io/tracing.out", "w")
f.write(str(c) + " " + str(k_lower) + " " + str(k_upper if k_upper <= len(cows) else "Infinity"))
f.close()

