import sys

def check_query(s, t, q, illegal_chars):
    for ch in q:
        if ch in illegal_chars:
            return False
    p1 = 0
    p2 = 0
    while p1<len(s) and p2<len(t):
        while p1 < len(s) and s[p1] not in q:
            p1 += 1
        while p2 < len(t) and t[p2] not in q:
            p2 += 1

        if bool(p1==len(s)) ^ bool(p2==len(t)):
            return False
        if p1==len(s) and p2==len(s):
            return True
        if s[p1] != t[p2]:
            return False
        p1 += 1
        p2 += 1
    return True    

s = sys.stdin.readline()[:-1]
t = sys.stdin.readline()[:-1]

sfreq = {}
for ch in s:
    sfreq[ch] = sfreq.get(ch, 0) + 1
tfreq = {}
for ch in t:
    tfreq[ch] = tfreq.get(ch, 0) + 1

illegal_chars = set()
for ch in list("abcdefghijklmnopqr"):
    if ch not in sfreq or ch not in tfreq or sfreq[ch] != tfreq[ch]:
        illegal_chars.add(ch)

#solve
queries = int(sys.stdin.readline())
for _ in range(queries):
    if check_query(s, t, sys.stdin.readline()[:-1], illegal_chars):
        print('Y', end='')
    else:
        print('N', end='')

