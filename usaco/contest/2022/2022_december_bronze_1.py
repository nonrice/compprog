import sys
amt = int(sys.stdin.readline())
cows = [False if x=="H" else True for x in list(sys.stdin.readline())]

lonely = 0

for size in range(3, amt+1):
    g_cows = 0
    h_cows = 0
    for x in range(0, size):
        g_cows += cows[x]
        h_cows += not(cows[x])

    if g_cows == 1 or h_cows == 1:
        lonely += 1

    for i in range(0, amt-size):
        g_cows -= cows[i]
        h_cows -= not (cows[i])
        g_cows += cows[i+size]
        h_cows += not (cows[i+size])

        if g_cows == 1 or h_cows == 1:
            lonely += 1

print(lonely)
