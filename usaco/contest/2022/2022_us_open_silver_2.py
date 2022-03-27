import sys
from collections import deque

def check_query(s, t, q):
    s1 = []
    s2 = []
    for ch in s:
        if ch in q:
            s1.append(ch)

    for ch in t:
        if ch in q:
            s2.append(ch)

    if len(s1) != len(s2):
        return False

    return len(s1)>0 and s1==s2

s = sys.stdin.readline()[:-1]
t = sys.stdin.readline()[:-1]

pool = list("abcdefghijklmnopqr")
comb_queue = deque(pool)
valid_queries = set()

while len(comb_queue):
    q = comb_queue.popleft()
    if check_query(s, t, q):
        valid_queries.add(q)
        for ch in pool:
            if ch not in q:
                comb_queue.append("".join(sorted(q + ch)));

print('here')

#solve
queries = int(sys.stdin.readline())
for _ in range(queries):
    if sys.stdin.readline()[:-1] in valid_queries:
        print('Y', end='')
    else:
        print('N', end='')

