s = input()
n = len(s)
for i in range(n//2+1, n):
    if s[:i] == s[-i:]:
        print("YES")
        print(s[:i])
        exit(0)
print("NO")
