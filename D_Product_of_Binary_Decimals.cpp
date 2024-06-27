def check(n):
    while n > 0:
        r = n % 10
        if r == 1 or r == 0:
            n = n // 10
            continue
        return False
    return True

v = [i for i in range(1, 10**5 + 1) if check(i)]

t = int(input())
for _ in range(t):
    n = int(input())
    ix = len(v) - 1
    while n > 0 and ix >= 0:
        if n % v[ix] == 0 and v[ix] != 1:
            n = n // v[ix]
            continue
        ix -= 1
    if n > 1:
        print("NO")
    else:
        print("YES")
