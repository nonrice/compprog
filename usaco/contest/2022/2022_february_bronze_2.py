import sys

n = int(sys.stdin.readline())
start = [int(x) for x in sys.stdin.readline().split()]

end = [int(x) for x in sys.stdin.readline().split()]
prev = [i-1 for i in range(len(start))]
after = [i+1 for i in range(len(start))]
after[-1] = -1
lookup = {x:i for i,x in enumerate(start)}

moves = 0
for num in end:
    index = lookup[num]
    if prev[index] != -1:
        moves += 1
    
    if index < len(prev)-1:
        prev[after[index]] = prev[index]
        after[prev[index]] = after[index]

print(moves)