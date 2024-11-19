import sys

def solve(nums, x):
    nums = sorted(nums)
    freq = {}
    for num in nums:
        freq[num] = freq.get(num, 0)+1
    
    needed = len(nums)
    for num in nums:
        if freq[num]>0 and freq.get(num*x, 0)>0:
            freq[num*x] -= 1
            freq[num] -= 1
            needed -= 2

    return needed

cases = int(sys.stdin.readline())
for _ in range(cases):
    header = [int(x) for x in sys.stdin.readline().split()]
    n, x = header[0], header[1]
    nums = [int(x) for x in sys.stdin.readline().split()]
    print(solve(nums, x))

