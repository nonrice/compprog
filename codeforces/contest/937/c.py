for _ in range(int(input())):
    h, m = input().split(':')

    if int(h) > 0 and int(h) <= 12:
        print(h+':'+m + (" AM" if int(h)!=12 else " PM"))
    else:
        rh = h
        h = str(abs(int(h)-12))
        if len(h)==1:
            h = "0"+h
        print(h+':'+m + (" PM" if int(rh)!=0 else " AM"))

