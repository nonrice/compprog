
def find_max_r(cows):
    r_lim = len(cows)
    for i in range(0, len(cows)):
        if cows[i][1] == 0:
            closest_cow = min((cows[i][0] - cows[i-1][0]) if i > 0 and cows[i-1][1] == 1 else len(cows), (cows[i+1][0] - cows[i][0]) if i < len(cows)-1 and cows[i+1][1] == 1 else len(cows))
            if closest_cow < r_lim:
                r_lim = closest_cow
    return r_lim-1

def count_islands(cows, r):
    islands = 1
    for i in range(1, len(cows)):
        if cows[i][0] - cows[i - 1][0] > r and cows[i][1] != 0:
            islands += 1
    return islands

with open("io/socdist2.in") as f:
    cows = []
    for cow in f:
        if len(cow.split(" ")) > 1:
            cows.append([int(cow.split(" ")[0]), int(cow.split(" ")[1])])

cows = sorted(cows,key=lambda x: (x[0]))
print(cows)

f = open("io/socdist2.out", "w")
f.write(str(count_islands(cows, find_max_r(cows))))
print(str(count_islands(cows, find_max_r(cows))))
f.close()