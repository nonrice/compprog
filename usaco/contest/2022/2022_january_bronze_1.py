import sys

truth = dict()
for i in range(3):
    row = list(sys.stdin.readline())

    for j in range(3):
        if row[j] not in truth:
            truth[row[j]] = set()
        truth[row[j]].add((i, j))


guess = dict()
for i in range(3):
    row = list(sys.stdin.readline())

    for j in range(3):
        if row[j] not in guess:
            guess[row[j]] = set()
        guess[row[j]].add((i, j))    

green = 0
yellow = 0

for key in guess:
    if key in truth:
        x = len(guess[key] & truth[key])
        green += x
        yellow += min(len(guess[key]), len(truth[key])) - x

print(green)
print(yellow)

