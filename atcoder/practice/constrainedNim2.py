# Unoriginal problem :|

n, l, r = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

g_ans = 0
for sz in a: g_ans ^= sz%(l+r)//l

if g_ans: print("First")
else: print("Second")
