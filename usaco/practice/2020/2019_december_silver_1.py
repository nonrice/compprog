f = open("moobuzz.in")
n = int(f.readline()[:-1])

def check_result(x, n):
    return n == (x - (x//3 + x//5) + x//15)

approx = (15*n)//8 

dist = 0
f = open("moobuzz.out", "w")
while True:
    if check_result(approx+dist, n):
        f.write(str(approx+dist))
        break
    elif check_result(approx-dist, n):
        f.write(str(approx-dist))
        break

    dist += 1

f.close()
