for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    for i in range(0, n-(3 if n%2 else 0), 2):
        print(f"{a[i+1]} {-a[i]}", end = " ")
    
    if n%2:
        if -a[-3]-a[-2] != 0:
            print(f"{a[-1]} {a[-1]} {-a[-3]-a[-2]}")
        elif -a[-3]-a[-1] != 0:
            print(f"{a[-2]} {-a[-3]-a[-1]} {a[-2]}")
        else:
            print(f"{-a[-1]-a[-2]} {a[-3]} {a[-3]}")
    else:
        print()


