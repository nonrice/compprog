import sys

for _ in range(int(sys.stdin.readline())):
    sys.stdin.readline()
    line = [int(x) for x in sys.stdin.readline().split()]
    largest = max(line)
    total = sum(line)
    if largest*2 <= total:
        print(1 if total>0 else 0)
    else:
        print(2*largest - total)
