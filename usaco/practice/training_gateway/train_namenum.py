"""
ID: widefin1
TASK: namenum
LANG: PYTHON3
"""

def ch_to_num(ch):
    if ch in "ABC": return 2
    elif ch in "DEF": return 3
    elif ch in "GHI": return 4
    elif ch in "JKL": return 5
    elif ch in "MNO": return 6
    elif ch in "PRS": return 7
    elif ch in "TUV": return 8
    elif ch in "WXY": return 9

def name_to_num(name):
    return [ch_to_num(ch) for ch in name]

cow = []
with open("namenum.in", "r") as f:
    cow = [int(x) for x in f.readline()[:-1]]

names = []
with open("dict.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        if name_to_num(line[:-1]) == cow:
            names.append(line[:-1])

with open("namenum.out", "w") as f:
    for name in names:
        f.write(name+"\n")
    if not names:
        f.write("NONE\n")

