def print_checkerboard(n):
    if n == 1:
        return '##'
    else:
        return '..'

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        for i in range(2 * n):
            for j in range(n):
                if (i // 2 + j) % 2 == 0:
                    print(print_checkerboard(1), end='')
                else:
                    print(print_checkerboard(0), end='')
            print()


solve()
