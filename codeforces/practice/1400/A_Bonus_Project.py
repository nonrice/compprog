n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

s = [0]*n
s[n-1] = a[n-1]//b[n-1]
for i in range(n-1, -1, -1):
	s[i] = s[i+1] + a[i]//b[i]
