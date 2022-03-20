"""
ID: widefin1
TASK: milk2
LANG: PYTHON3
"""

f = open("milk2.in")
amt = int(f.readline())
milking = []
for i in range(amt):
    milking.append([int(x) for x in f.readline().split()])

milking = sorted(milking, key=lambda x: x[0])
print(milking)

max_int_milking = milking[0][1] - milking[0][0]
max_int_idle = 0
start = milking[0][0]
end = milking[0][1]

for i in range(1, len(milking)):
    if end < milking[i][0]:
        milking_len = end - start
        idle_len = milking[i][0] - end

        if milking_len > max_int_milking:
            max_int_milking = milking_len
        if idle_len > max_int_idle:
            max_int_idle = idle_len

        start = milking[i][0]
        end = milking[i][1]
    else:
        if milking[i][1] > end:
            end = milking[i][1]

print(max_int_milking, max_int_idle)

f = open("milk2.out", "w")
f.write(str(max_int_milking) + " " + str(max_int_idle) + "\n")
f.close()