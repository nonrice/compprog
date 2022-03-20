f = open("photo.in")
n = int(f.readline()[:-1])
cows = [int(x) for x in f.readline()[:-1].split()]
f.close()

def is_valid_sequence(n, k, cows):
    prev = k
    seen = set([prev])
    for cow in cows:
        if cow-prev==prev or cow-prev<=0 or cow-prev>n:
            return False 
        prev = cow-prev
        seen.add(prev)
    return len(seen) == n

def gen_sequence(k, cows):
    prev = k
    sequence = str(prev)
    for cow in cows:
        prev = cow - prev
        sequence += " " + str(prev)
    return sequence

found = False
for i in range(1, cows[0]):
    if is_valid_sequence(n, i, cows):
        f = open("photo.out", "w")
        f.write(gen_sequence(i, cows))
        f.close()
        break  
    