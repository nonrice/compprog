import sys

count = int(sys.stdin.readline()[:-1])
cows = [int(x) for x in sys.stdin.readline().split()]
stalls = sorted([int(x) for x in sys.stdin.readline().split()])

def count_eligible(cows, stall_height):
    eligible = 0
    for x in cows:
        if x <= stall_height:
            eligible += 1
    
    return eligible

permutations = 1
subtract = 0

for x in stalls:
    permutations *= count_eligible(cows, x) - subtract
    subtract += 1

print(permutations)