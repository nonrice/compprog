from math import ceil

def try_d(d, segments, n):
    cur_cow = segments[0][0]
    cur_seg = 0
    while n > 1:
        cur_cow += d
        n -= 1
        if cur_cow > segments[cur_seg][1]:
            while cur_cow > segments[cur_seg][1]:
                cur_seg += 1
                if cur_seg >= len(segments):
                    return False

            cur_cow = max(cur_cow, segments[cur_seg][0]) 
    
    return True

with open("socdist.in") as f:
    header = [int(x) for x in f.readline()[:-1].split()]
    n, m = header[0], header[1]
    segments = sorted([[int(x) for x in f.readline()[:-1].split()] for i in range(m)])

l = 1
r = ceil((segments[-1][1] - segments[0][0])/(n-1))
while l <= r:
    m = (r+l)//2
    if try_d(m, segments, n):
        max_valid = m
        l = m+1
    else:
        r = m-1

with open("socdist.out", "w") as f:
    f.write(str(max_valid))