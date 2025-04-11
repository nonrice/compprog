f = {
    0: "la",
    1: "le",
    2: "lon",
    3: "sha",
    4: "she",
    5: "shon",
    6: "ta",
    7: "te",
    8: "ton",
}
g = {(v, k) for k, v in f.items()}


def to_dec(s):
    ans = 0
    while len(s) > 1:
        for k, v in g:
            if s.find(k) == 0:
                ans *= 9
                ans += v
                s = s[len(k) :]
                break
    return ans


def to_scr(x):
    d = []
    while x:
        d.append(f[x % 9])
        x //= 9
    return "".join(reversed(d)) + "s"


a, b = input().split()

print(to_scr(to_dec(a) + to_dec(b)))
