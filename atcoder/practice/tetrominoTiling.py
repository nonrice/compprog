I, O, T, J, L, S, Z = map(int, input().split())

ans = I + J + L + O - I%2 - J%2 - L%2
if min(I, J, L) >= 1:
    ans = max(ans, 3 + I-1 + J-1 + L-1 + O - (I-1)%2 - (J-1)%2 - (L-1)%2)

print(ans)
