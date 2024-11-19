f = open("outofplace.in")
n = int(f.readline()[:-1])
cows = []
for x in range(n):
    cows.append(int(f.readline()[:-1]))

def find_neighbours(cows, i):
    if i == 0:
        return -1, cows[i], cows[i+1]
    elif i == len(cows)-1:
        return cows[i-1], cows[i], 987654321
    else:
        return cows[i-1], cows[i], cows[i+1]

swaps = False

for i in range(len(cows)):
    prev, cur, next = find_neighbours(cows, i)
    if cur < prev:
        x = i-1
        while cows[x] > cur:
            x -= 1
        swaps = len(set(cows[x+1:i]))
        break

if swaps:
    f = open("outofplace.out", "w")
    f.write(str(swaps))
    f.close()
    exit()

for i in range(len(cows)):
    prev, cur, next = find_neighbours(cows, i)
    if cur > next and cur > prev:
        x = i+1
        while cows[x] < cur:
            x += 1
        swaps = len(set(cows[i+1:x]))
        break

f = open("outofplace.out", "w")
f.write(str(swaps))
f.close()
        