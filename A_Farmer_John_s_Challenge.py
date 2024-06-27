def solve():
    n, k = map(int, input().split())

    if k > 1 and k != n:
        print(-1)
        return

    ans = [2] * n
    for i in range(k):
        ans[n - i - 1] = 1

    for i in ans:
        print(i, end=" ")
    print()

t = int(input())
for _ in range(t):
    solve()
