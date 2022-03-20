import sys

# (it times out after first 4 cases)

# This is basically KSUM problem:
# 1 sort input by x val
# 2 make k sum call k-1 sum
# 3 2 sum (2 pointers) when k=2
# 4 check y sum for those that pass 2 sum
# 5 add to counter if yes

def two_sum(commands, start, target, x_lookup):
    count = 0
    for i in range(start, len(commands)):
        command = commands[i]
        complement = target[0] - command[0]
        if complement in x_lookup:
            for j in x_lookup[complement]:
                if j >= start and j > i:
                    if command[1] + commands[j][1] == target[1]:
                        count += 1

    return count

def k_sum(commands, k, start, target, x_lookup):
    result = 0

    if k == 2:
        return two_sum(commands, start, target, x_lookup)
    if k == 1:
        for i in range(start, len(commands)):
            if commands[i] == target:
                result += 1
        return result

    for i in range(start, len(commands)-(k-1)):
        cur_command = commands[i]
        result += k_sum(commands, k-1, i+1, (target[0]-cur_command[0], target[1]-cur_command[1]), x_lookup)
    
    return result

n = int(sys.stdin.readline())
target = tuple([int(x) for x in sys.stdin.readline().split()])
commands = [tuple([int(x) for x in sys.stdin.readline().split()]) for x in range(n)]
commands = sorted(commands, reverse=True)

x_lookup = {}
for i in range(len(commands)):
    command = commands[i]
    if command[0] not in x_lookup:
        x_lookup[command[0]] = [i]
    else:
        x_lookup[command[0]].append(i)

for k in range(1, len(commands)+1):
    print(k_sum(commands, k, 0, target, x_lookup))
