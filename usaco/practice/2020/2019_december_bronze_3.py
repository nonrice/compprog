from itertools import permutations

f = open("lineup.in")
n = int(f.readline()[:-1])
instructions = []

for x in range(n):
    instruction = f.readline()[:-1].split()
    instructions.append([instruction[0], instruction[5]])

cows = [
    "Beatrice",
    "Belinda",
    "Bella",
    "Bessie",
    "Betsy",
    "Blue",
    "Buttercup",
    "Sue"
]

def check_permutation(perm, instructions):
    for instruct in instructions:
        if abs(perm.index(instruct[0])-perm.index(instruct[1])) != 1:
            return False
    
    return True

perms = permutations(cows)
for perm in perms:
    if check_permutation(perm, instructions):
        f = open("lineup.out", "w")
        for cow in perm:
            f.write(cow + "\n")
        f.close()
        break
