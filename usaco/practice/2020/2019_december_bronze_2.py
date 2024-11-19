f = open("whereami.in")
n = int(f.readline()[:-1])
s  = f.readline()[:-1]

for size in range(1, len(s)+1):
    sequences = set()
    found_k = True

    for i in range(0, len(s)-size+1):
        l = len(sequences)
        sequences.add(s[i:i+size])
        print(sequences)
        if len(sequences) == l:
            found_k = False
            break

    if found_k == True:
        break

if found_k:
    f = open("whereami.out", "w")
    f.write(str(size))
    f.close()
    