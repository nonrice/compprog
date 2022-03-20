import sys
count = int(sys.stdin.readline()[:-1])

n_cows = []
e_cows = []

for x in range(count):
    cow = sys.stdin.readline()[:-1].split()
    if cow[0] == "N":
        n_cows.append([cow[0], int(cow[1]), int(cow[2]), x])
    else:
        e_cows.append([cow[0], int(cow[1]), int(cow[2]), x])

n_cows = sorted(n_cows, key=lambda x: x[1])
e_cows = sorted(e_cows, key=lambda x: x[2])


def check_collide(xn, yn, xe, ye):
    delta_x = xn-xe
    delta_y = ye-yn

    if delta_x > 0 and delta_y > 0:
        if delta_x > delta_y:
            return "E", delta_x
        elif delta_x < delta_y:
            return "N", delta_y
    
    return None, None

consumed_grass = [-1] * count

for n in range(len(n_cows)):
    for e in range(len(e_cows)):
        if e_cows[e][0] == "E":
            direction, grass = check_collide(n_cows[n][1], n_cows[n][2], e_cows[e][1], e_cows[e][2])
            if direction == "E":
                consumed_grass[e_cows[e][3]] = grass
                e_cows[e][0] = "stop"
            elif direction == "N":
                consumed_grass[n_cows[n][3]] = grass
                break

for x in consumed_grass:
    if x >= 0:
        print(x)
    else:
        print("Infinity")
