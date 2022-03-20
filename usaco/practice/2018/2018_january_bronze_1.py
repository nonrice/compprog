f = open("billboard.in")
lawnmower = [int(x) for x in f.readline()[:-1].split()]
feed = [int(x) for x in f.readline()[:-1].split()]

x1, y1, x2, y2 = lawnmower[0], lawnmower[1], lawnmower[2], lawnmower[3]
x3, y3, x4, y4 = feed[0], feed[1], feed[2], feed[3]

tarp = (y2-y1) * (x2-x1)
if x4>=x2 and x3<=x1 and y4>=y2 and y3<=y1:
    tarp = 0
elif x4>=x2 and x3<=x1:
    if y1<=y3<=y2 and not y1<y4<y2:
        tarp = (x2-x1) * (y3-y1)
    elif y1<=y4<=y2 and not y1<y3<y2:
        tarp = (x2-x1) * (y2-y4)
elif y4>=y2 and y3<=y1:
    if x1<=x3<=x2 and not x1<x4<x2:
        tarp = (y2-y1) * (x3-x1)
    elif x1<=x4<=x2 and not x1<x3<x2:
        tarp = (y2-y1) * (x2-x4)

f = open("billboard.out", "w")
f.write(str(tarp))
f.close()
