"""
ID: widefin1
LANG: PYTHON3
TASK: gift1
"""

f = open("gift1.in")
people_amt = int(f.readline())
people = {}
for i in range(people_amt):
    people[f.readline()[:-1]] = 0

for i in range(people_amt):
    person = f.readline()[:-1]
    stats = [int(x) for x in f.readline().split()]
    budget = stats[0]
    shares = stats[1]

    if shares != 0:
        people[person] += (budget % shares) - budget
        gift_amt = budget // shares
    else:
        people[person] += budget
        gift_amt = 0

    for j in range(shares):
        people[f.readline()[:-1]] += gift_amt

f = open("gift1.out", "w")
for key in people:
    f.write(key + " " + str(people[key]) + "\n")

f.close()
