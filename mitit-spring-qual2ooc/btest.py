import random

a = [1,2,3,4,5,6,7,8,9]
random.shuffle(a)

def med(a):
    b = sorted(a.copy())
    return b[len(b)//2]

c = []
for i in range(0, len(a)-2):
    c.append(med(a[i:i+3]))

print(a)
print(c)
print(med(c))

