import sys
count = int(sys.stdin.readline()[:-1])
for i in range(count):
    cmds = sys.stdin.readline()[:-1]
    turns_r = 0
    for j in range(1, len(cmds)):
        prev_char = cmds[j-1]
        char = cmds[j]
        if prev_char == "N":
            if char == "E":
                turns_r += 1
            elif char == "W":
                turns_r -= 1
        if prev_char == "E":
            if char == "S":
                turns_r += 1
            elif char == "N":
                turns_r -= 1
        if prev_char == "S":
            if char == "W":
                turns_r += 1
            elif char == "E":
                turns_r -= 1
        if prev_char == "W":
            if char == "N":
                turns_r += 1
            elif char == "S":
                turns_r -= 1
        
    if turns_r > 0:
        print("CW")
    elif turns_r < 0:
        print("CCW")
