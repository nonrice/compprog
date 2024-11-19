for _ in range(int(input())):
    s = input()
    
    for i in range(0, 6):
        if s.find("calico"[i:]) == 0:
            print("CALICO" + s[(6-i):])
            break
    else:
        print(s)
