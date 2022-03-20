f = open("lifeguards.in")
n = int(f.readline()[:-1])
intervals = []
for i in range(n):
    intervals.append([int(x) for x in f.readline()[:-1].split()])
intervals = sorted(intervals, key=lambda x: x[0])
f.close()

def calc_coverage(intervals, fired):
    if fired > 0:
        start, end = intervals[0][0], intervals[0][1]
    else:
        start, end = intervals[1][0], intervals[1][1]

    coverage = 0
    for i in range(len(intervals)):
        if i == fired:
            continue
        if intervals[i][0] > end:
            coverage += end-start
            start = intervals[i][0]
            end = intervals[i][1]
        else:
            if intervals[i][1] > end:
                end = intervals[i][1]

    coverage += end-start
    return coverage

max_coverage = 0
for x in range(n):
    coverage = calc_coverage(intervals, x)
    print(coverage)
    if coverage > max_coverage:
        max_coverage = coverage

f = open("lifeguards.out", "w")
f.write(str(max_coverage))
f.close()
