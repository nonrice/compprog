import math
v, theta, x, y, t = (int(x) for x in input().split())
vx=v*math.cos(theta*2*math.pi/360)
vy=v*math.sin(theta*2*math.pi/360)
x1=x+vx*t
y1=y+vy*t-1/2*9.80665*t*t
print(x1, y1)