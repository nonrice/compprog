import sys, math

def count_merges(arr):
    n = sum(arr)

    for f in range(1, n+1):
        if n%f == 0:
            total = 0
            merges = 0
            new_element = True

            for x in arr:
                if new_element:
                    new_element = False
                else:
                    merges += 1

                total += x

                if total > f:
                    merges = -1
                    break;
                if total == f:
                    total = 0
                    new_element = True
            
            if merges > -1:
                return merges
        
    return 0

t = int(sys.stdin.readline())
for x in range(t):
    length = int(sys.stdin.readline())
    classes = [int(n) for n in sys.stdin.readline().split()]

    print(count_merges(classes))