from functools import cache

@cache
def dp(n):
    if n == 1:
        return [1]

    p_ans = dp(n-2)
    ans = []
    for v in p_ans:
        ans.append(v*100 + 64)
    ans.append(p_ans[0]*100 + 16)
    ans.append(p_ans[1]*100 + 16)
