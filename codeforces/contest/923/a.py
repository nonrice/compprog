for _ in range(int(input())):
    n = int(input())
    s = input()
    l, r = -1, 0
    for i, c in enumerate(s):
        if c == 'B':
            if l == -1:
                l = i
            r = i
    if l == -1:
        print(0)
    print(r-l+1);

