f = open("socdist1.in", "r")
f.readline()
stalls = [int(x) for x in str(f.readline()[:-1])]

def largest_pockets_index(stalls):
    largest_A = -1
    largest_A_index = -1
    largest_B = -1
    largest_B_index = -1
    cur_pocket = 0
    cur_pocket_index = 0
    stalls.append(1)
    for i in range(0, len(stalls)):
        if stalls[i] == 1:
            if cur_pocket >= largest_A:
                largest_B = largest_A
                largest_B_index = largest_A_index
                largest_A = cur_pocket
                largest_A_index = cur_pocket_index
            elif cur_pocket > largest_B:
                largest_B = cur_pocket
                largest_B_index = cur_pocket_index
            cur_pocket = 0
            cur_pocket_index = i+1
        else:
            cur_pocket += 1
    stalls.pop()
    return largest_A, largest_A_index, largest_B, largest_B_index

def index_of(x, iterable):
    for i, item in enumerate(iterable):
        if item == x:
            return i
    return 0

def calc_d(stalls):
    d = len(stalls)
    cur_distance = 0
    for stall in range(index_of(1, stalls)+1, len(stalls)):
        cur_distance += 1
        if stalls[stall] == 1:
            if cur_distance < d:
                d = cur_distance
            cur_distance = 1

    return d


largest_A, largest_A_index, largest_B, largest_B_index = largest_pockets_index(stalls)
print(stalls)
print(largest_A, largest_A_index, largest_B, largest_B_index)
a_end = ((largest_A_index+largest_A==len(stalls)) and stalls[-1] == 0) or (largest_A_index == 0 and stalls[0] == 0)
b_end = ((largest_B_index+largest_B==len(stalls)) and stalls[-1] == 0) or (largest_B_index == 0 and stalls[0] == 0)
print(a_end, b_end)
if largest_B > 0:
    s1 = min(largest_A//(2-a_end)+1-a_end, largest_B//(2-b_end)+1-b_end)
else:
    s1 = 0
s2 = max(largest_A//(3-a_end)+1-a_end, largest_B//(3-b_end)+1-a_end)
print(s1, s2)

f = open("socdist1.out", "w")
f.write(str(max(s1, s2)))
f.close()