import sys
from tabnanny import check

n = int(sys.stdin.readline())
pairs = []
for i in range(n):
    line = [str(int(x)-1) for x in sys.stdin.readline().split()]
    a = int("".join(line[0:4]))
    b = int("".join(line[4:8]))
    pairs.append([a, b])

def get_digit(number, n):
    return number // 10**n % 10

def check_win(a, b):
    a_win = 0
    b_win = 0

    for i in range(0, 4):
        for j in range(0, 4):
            a_roll = get_digit(a, i)
            b_roll = get_digit(b, j)
            if a_roll > b_roll:
                a_win += 1
            elif b_roll > a_roll:
                b_win += 1
    
    return a_win > b_win

for pair in pairs:
    found = False
    for c in range(0, 9999):
        if check_win(pair[0], pair[1]):
            if check_win(pair[1], c) and check_win(c, pair[0]):
                found = True
                print("yes")
                break
        else:
            if check_win(pair[0], c) and check_win(c, pair[1]):
                found = True
                print("yes")
                break
    if not found:
        print("no")
