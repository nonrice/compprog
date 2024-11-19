import sys, itertools

def is_spellable(blocks, word):
    orders = tuple(itertools.permutations(range(4), len(word)))

    for order in orders:
        found = True
        for i, c in enumerate(word):
            if c not in blocks[order[i]]:
                found = False
                break       

        if found:
            return True
    
    return False

n = int(sys.stdin.readline())
blocks = [sys.stdin.readline()[:-1] for x in range(4)]
words = [sys.stdin.readline()[:-1] for x in range(n)]

for word in words:
    print("YES" if is_spellable(blocks, word) else "NO")
