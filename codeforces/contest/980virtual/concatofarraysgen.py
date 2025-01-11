from random import shuffle

x = 1000 

print(x)
a = [1, 2, 3, 4, 5, 6]
for _ in range(x):
    shuffle(a)
    print(3)
    print(a[0], a[1])
    print(a[2], a[3])
    print(a[4], a[5])

