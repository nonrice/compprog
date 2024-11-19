"""
ID: widefin1
TASK: friday
LANG: PYTHON3
"""

f = open("friday.in")
n = int(f.readline())


def day_to_weekday(day):
    return day%7

def is_leap_year(yr):
    return yr % 4 == 0 and yr != 1900 and yr != 2100 and yr != 2200

def yr_to_day(yr):
    if yr==1900:
        return 0
    days = (yr-1900)*365 + (yr-1-1900)//4
    if yr > 2200:
        return days-2
    if yr > 2100:
        return days-1
    return days

targets = [13, 44, 72, 103, 133, 164, 194, 225, 256, 286, 317, 347]
targets_leap = [13, 44, 73, 104, 134, 165, 195, 226, 257, 287, 318, 348]

days = [0, 0, 0, 0, 0, 0, 0]

for i in range(n):
    yr = 1900+i
    dd = targets_leap if is_leap_year(yr) else targets
    for x in dd:
        days[day_to_weekday(x + yr_to_day(yr))] += 1


print(days[6], days[0], days[1], days[2], days[3], days[4], days[5])
f = open("friday.out", "w")
f.write(str(days[6])+" "+str(days[0])+" "+str(days[1])+" "+str(days[2])+" "+str(days[3])+" "+str(days[4])+" "+str(days[5])+"\n")
f.close()