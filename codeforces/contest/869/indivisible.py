for _ in range(int(input())):
    x = int(input())

    if x == 1:
        print("1")
        continue
    
    if x%2 == 1:
        print("-1")
        continue

    for i in range(0, x, 2):
        print(i+2, i+1, end=" ")
    print("")
