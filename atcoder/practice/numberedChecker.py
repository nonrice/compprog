# arb precis ftw

# later, I find div mod n is just to mulitply mod inverse so cpp works fine

[n, m] = [int(x) for x in input().split()]
 
def get(i, j):
    return 0 if (i+j)%2 else (i-1)*m+j
 
for _ in range(int(input())):
    [a, b, c, d] = [int(x) for x in input().split()]
    l1 = c + (not bool(get(a, c)))
    r1 = d - (not bool(get(a, d)))
    l2 = c + (not bool(get(a+1, c)))
    r2 = d - (not bool(get(a+1, d)))
    
    h1 = (b-a+1+1)//2
    h2 = (b-a+1)//2
    cnt1 = (r1-l1)//2 + 1
    cnt2 = (r2-l2)//2 + 1
    
    s1 = h1 * (get(a,l1) + get(a,r1))*cnt1//2 + 2*m * cnt1 * (h1*(h1-1)//2)
    s2 = h2 * (get(a+1,l2) + get(a+1,r2))*cnt2//2 + 2*m * cnt2 * (h2*(h2-1)//2)
    
    print((s1 + s2)%998244353)
