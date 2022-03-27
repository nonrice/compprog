import sys

def check_twol(s, t, a, b):
    p1 = 0
    p2 = 0
    while p1 < len(a) and p2 < len(b):
        if s[p1] != a and s[p1] != b:
            p1 += 1
        if t[p2] != a and t[p2] != b:
            p2 += 1
        if s[p1] == a or s[p1] == b and t[p2] == a or t[p2] == b:
            if s[p1] != t[p2]:
                return False
            p1 += 1
            p2 += 1
    return True

def check_query(s, t, q, twol_map):
    for i in range(1, len(q)):
        if not twol_map[(q[i], q[i-1])]:
            return False
    return True


s = sys.stdin.readline()[:-1]
t = sys.stdin.readline()[:-1]

twol_map = {}
for a in range(97, 115): # letter a to r
    for b in range(97, 115):
        twol_map[(chr(a), chr(b))] = check_twol(s, t, chr(a), chr(b))

for k in twol_map:
    print(k, twol_map[k])

queries = int(sys.stdin.readline())
for _ in range(queries):
    q = sys.stdin.readline()[:-1]
    if check_query(s, t, q, twol_map):
        print('Y', end='')
    else:
        print('N', end='')

