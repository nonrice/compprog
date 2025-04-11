import bisect
n, q = (int(x) for x in input().split())
arr=[int(x) for x in input().split()]
pref=[0]
for a in arr:
    pref.append(pref[-1]+a)
for _ in range(q):
    a = int(input())
    i=bisect.bisect_left(pref, a)
    if i<len(pref)-1:
        print(min(abs(a-pref[i]), abs(a-pref[i-1])))
    else:
        print(abs(a-pref[i-1]))