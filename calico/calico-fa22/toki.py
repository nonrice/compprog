
def is_vowel(ch):
    return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'

def solve():
    s = input()

    for ch in "bcdfghqrvxyz":
        if ch in s:
            print("ike")
            return

    for i in range(1, len(s)):
        if (is_vowel(s[i]) and is_vowel(s[i-1])):
            print("ike")
            return

        for seq in ["wu", "wo", "ji", "ti", "nn", "nm"]:
            if (s[i-1]==seq[0]) and s[i]==seq[1]:
                print("ike")
                return

    w = s.replace('a', ' ').replace('e', ' ').replace('i', ' ').replace('o', ' ').replace('u', ' ').split()
    if (is_vowel(s[0])): w.insert(0, "")
    if (is_vowel(s[len(s)-1])): w.append("")

    if (len(w)<2):
        print("ike")
        return

    if (len(w[len(w)-1])==1 and w[len(w)-1] != 'n'):
        print("ike")
        return

    for i in range(0, len(w)-1):
        if (len(w[i]) > 2):
            print("ike")
            return

    print("pona")


for _ in range(int(input())):
    solve()
