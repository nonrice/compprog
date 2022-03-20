"""
ID: widefin1
TASK: beads
LANG: PYTHON3
"""

f = open("io/beads.in")
amt = int(f.readline())
beads = list(f.readline()[:-1])

print(beads)

def make_groups(split, beads):
    color = beads[split]
    size_l = 0
    i = split
    while beads[i] == color or beads[i] == "w" or color == "w":
        if beads[i] != color and color == "w":
            color = beads[i]

        i -= 1
        size_l += 1

        if i < 0:
            i = len(beads) - 1
        if i == split:
            break

    color = beads[split+1 if split<len(beads)-1 else 0]
    size_r = 0
    i = split+1 if split<len(beads)-1 else 0
    while beads[i] == color or beads[i] == "w" or color == "w":
        if beads[i] != color and color == "w":
            color = beads[i]

        i += 1
        size_r += 1

        if i > len(beads)-1:
            i = 0
        if i == split:
            break

    return size_l, size_r

x = 0
max_beads = 0
while x < amt:
    size_l, size_r = make_groups(x, beads)
    print(x, size_l, size_r)
    if min(amt, size_l + size_r) > max_beads:
        max_beads = min(amt, size_l + size_r)
    x += max(size_r, 1)


print(max_beads)

f = open("beads.out", "w")
f.write(str(max_beads) + "\n")
f.close()
