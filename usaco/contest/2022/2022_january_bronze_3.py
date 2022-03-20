import sys
n = int(sys.stdin.readline())
cows = []
for i in range(n):
    sys.stdin.readline()
    cows.append([int(x) for x in sys.stdin.readline().split()])

def solve(cows):
    steps = 0
    for i in range(0, len(cows), 2):
        if i > 0:
            if cows[i] < cows[i-1]:
                diff = cows[i-1] - cows[i]
                steps += diff * (i)
                cows[i-1] -= diff
            elif cows[i] > cows[i-1]:
                diff = cows[i] - cows[i-1]
                cows[i] -= diff
                cows[i+1] -= diff
                steps += diff * 2
        if i < len(cows)-1:
            if cows[i] > cows[i+1]:
                return -1
                #if i == 0:
                #    
                #diff = cows[i] - cows[i+1]
                #for q in range(i, -1, -1):
                #    cows[q] -= diff
                #    
                #if (i+1) % 2 == 0:
                #    steps += diff * (i+1)
                #else:
                #    return -1
            elif cows[i] < cows[i+1]:
                if i >= len(cows) - 2:
                    return -1
                diff = cows[i+1] - cows[i]
                cows[i+1] -= diff
                cows[i+2] -= diff
                steps += 2*diff

    for x in cows:
        if x < 0:
            return -1

    #if len(cows) % 2 == 0:
    #    if cows[-1] == cows[-2]:
    #        return steps + 2 * (cows[-1] - cows[-3])
    #else:
    #    return steps

    return steps
                

for cow_list in cows:
    print(solve(cow_list))