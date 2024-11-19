import sys

alphabet = list(sys.stdin.readline()[:-1])
speech = sys.stdin.readline()[:-1]

repeats = 1
prev_index = 0
for c in speech:
    if alphabet.index(c) <= prev_index:
        prev_index = alphabet.index(c)
        repeats += 1
    else:
        prev_index = alphabet.index(c)
    
print(repeats)
