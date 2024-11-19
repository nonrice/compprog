from collections import Counter

M = 998244353
def inv(x):
    return pow(x, M-2, M)

h, n, m = map(int, input().split())
r = Counter(list(map(int, input().split())))



