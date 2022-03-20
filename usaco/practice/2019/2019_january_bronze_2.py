f, out = open("sleepy.in"), open("sleepy.out", "w")
n = int(f.readline()[:-1]); c = [int(x) for x in f.readline()[:-1].split()]; f.close()
prev, stopped = c[-1], False
for x in range(n-1, -1  , -1): 
    if c[x] > prev: out.write(str(x+1)); out.close(); stopped = True; break
    else: prev = c[x]
if not stopped: out.write("0"); out.close()