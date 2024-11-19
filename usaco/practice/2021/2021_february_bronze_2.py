import sys
count = int(sys.stdin.readline()[:-1])

def add_cow(cow, cows, comfortable):
    adjacent = 0
    x = cow[0]
    y = cow[1]

    for c in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
        if c in cows:
            adjacent += 1
            cows[c] += 1
            neighbor = cows[c]
            if neighbor > 3:
                comfortable -= 1
            elif neighbor == 3:
                comfortable += 1

    cows[cow]= adjacent
    
    return cows, comfortable

cows = {}
comfortable = 0

for x in range(count):
    cow = tuple([int(x) for x in sys.stdin.readline()[:-1].split()])
    cows, comfortable = add_cow(cow, cows, comfortable)
    print(comfortable)

