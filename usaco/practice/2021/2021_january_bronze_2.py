import sys

size = int(sys.stdin.readline()[:-1])
cows = [int(x) for x in sys.stdin.readline().split()]

def count_nums(nums):
    even = 0
    odd = 0
    for x in nums:
        if x % 2 == 0:
            even += 1
        else:
            odd += 1

    return even, odd


even, odd = count_nums(cows)

if even > odd:
    print(2*odd+1)
elif even == odd:
    print(2*even)
else:
    cycle = (odd-even)%3
    if cycle == 1:
        modifier = -1
    elif cycle == 2:
        modifier = 1
    elif cycle == 0:
        modifier = 2

    print(even*2 + 2*((odd-even-1)//3) + modifier)
