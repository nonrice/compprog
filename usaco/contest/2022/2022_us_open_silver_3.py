import sys

s = sys.stdin.readline()[:-1]
pc = [0] * (1+len(s))
po = [0] * (1+len(s))
pw = [0] * (1+len(s))

for i, ch in enumerate(s):
    pc[i+1] = pc[i]
    po[i+1] = po[i]
    pw[i+1] = pw[i]
    if ch=='C':
        pc[i+1] = pc[i]+1
    elif ch=='O':
        po[i+1] = po[i]+1
    elif ch=='W':
        pw[i+1] = pw[i]+1

cases = int(sys.stdin.readline())
for _ in range(cases):
    case = [int(x) for x in sys.stdin.readline()[:-1].split()]
    l, r = case[0], case[1]
    c = pc[r] - pc[l-1]
    o = po[r] - po[l-1]
    w = pw[r] - pw[l-1]
    if (c+o)%2 and (o+w)%2==0:
        print('Y', end='')
    else:
        print('N', end='')