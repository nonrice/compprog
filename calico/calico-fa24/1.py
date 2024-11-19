for _ in range(int(input())):
    s = input()

    i = 0
    while i<len(s):
        if s[i] == 'O':
            print("[###OREO###]")
        elif s[i] == 'R':
            print(" [--------] ")
            i+=1
        else:
            print()
        i+=1
    
    
