s = input()

l = [0]*26
r = [0]*26
for c in s:
	r[ord(c)-65] += 1

ans = 0
for c in s:
	r[ord(c)-65] -= 1
	for i in range(0, 26):
		ans += l[i]*r[i]
	l[ord(c)-65] += 1

print(ans)
