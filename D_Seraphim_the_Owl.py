from functools import cmp_to_key
from typing import *

inf = float('inf')

for _ in range(int(input())):
    n, m = map(int, input().split())
    la = list(map(int, input().split()))
    lb = list(map(int, input().split()))

    s = 0
    ans = float('inf')

    for i in range(n-1, -1, -1):
        if i + 1 <= m:
            ans = min(ans, s + la[i])

        s += min(la[i], lb[i])

    print(ans)
