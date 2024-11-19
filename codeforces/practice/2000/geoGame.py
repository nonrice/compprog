import sys, io, os

def input():
    return sys.stdin.readline()

def print(s):
    sys.stdout.write(str(s))
    sys.stdout.write('\n')
    sys.stdout.flush()

def read_pt():
    x, y = map(int, input().split())
    return (x+y) % 2

for _ in range(int(input())):
    n = int(input())
    s = read_pt()
    c = [set(), set()]
    for i in range(1, n+1):
        c[read_pt()].add(i)
    t = 0 if len(c[0]) <= len(c[1]) else 1

    def read_mv():
        i = int(input())
        if i == -1:
            exit(0)
        if i in c[0]:
            c[0].remove(i)
        else:
            c[1].remove(i)

    def print_mv():
        if len(c[t]) > 0:
            print(c[t].pop()) 
        else:
            print(c[t^1].pop())

    if s^t == 1:
        print("First")
    elif len(c[0])==len(c[1]):
        print("First")
        t = s^1
    else:
        print("Second")
        read_mv()
    while len(c[0]) + len(c[1]) > 0:
        print_mv()
        if len(c[0]) + len(c[1]) > 0:
            read_mv()

