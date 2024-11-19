"""
ID: widefin
LANG: PYTHON3
TASK: acowdemia1
"""
import sys

l = int(sys.stdin.readline().split()[1])
citations_str = sys.stdin.readline().split()
citations = sorted([int(x) for x in citations_str], reverse=True)

def find_h(papers):
    for i in range(0, len(papers)):
        if papers[i] <= i:
            return i

ih = find_h(citations)
prev = citations[ih]
if ih==prev:
    for i in range(ih, -1, -1):
        if citations[i] != prev or i==0:
            group_size = ih-i+1 if i==0 else ih-i
            print(i)
            result = ih if group_size>l else ih+1
            break
        prev = citations[i]
else:
    result = ih

print(result)
