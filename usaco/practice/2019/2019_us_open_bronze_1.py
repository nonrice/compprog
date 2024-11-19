f = open("buckets.in")

barn = [0,0]
rock = [0,0]
lake = [0,0]

for y in range(10):
    line = f.readline()
    for x in range(10):
        if line[x] == "B":
            barn = [x, y]
        elif line[x] == "R":
            rock = [x, y]
        elif line[x] == "L":
            lake = [x, y]

print(barn)
print(rock)
print(lake)

reroute = False

if barn[0] == lake[0] == rock[0] and min(barn[1], lake[1]) < rock[1] < max(barn[1], lake[1]):
    reroute = True
elif barn[1] == lake[1] == rock[0] and min(barn[0], lake[0]) < rock[0] < max(barn[0], lake[0]):
    reroute = True

f = open("buckets.out", "w")

if reroute:
    f.write(str(abs(barn[0]-lake[0]) + abs(barn[1]-lake[1]) - 1 + 2))
else:
    f.write(str(abs(barn[0]-lake[0]) + abs(barn[1]-lake[1]) - 1))

f.close()

