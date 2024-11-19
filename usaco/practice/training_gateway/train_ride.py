"""
ID: widefin1
TASK: ride
LANG: PYTHON3
"""

def multiply_letters(code):
    x = 1
    for char in code:
        x *= ord(char)-64

    return x

f = open("ride.in")
comet = multiply_letters(f.readline()[:-1])
group = multiply_letters(f.readline()[:-1])
f.close()

f = open("ride.out", "w")
f.write(("GO" if comet%47 == group%47 else "STAY") + "\n")
f.close()