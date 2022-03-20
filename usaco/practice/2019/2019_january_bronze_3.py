f = open("guess.in")
n = int(f.readline()[:-1])
animals = {}
trait_freq = {}

for x in range(n):
    line = f.readline()[:-1].split()    
    animals[x] = set(line[2:])

max_yes = 0

for i in range(0, n-1):
    for j in range(i+1, n):
        common = len(animals[i].intersection(animals[j]))
        if common + 1 > max_yes:
            max_yes = common + 1

f = open("guess.out", "w")
f.write(str(max_yes))
f.close()
