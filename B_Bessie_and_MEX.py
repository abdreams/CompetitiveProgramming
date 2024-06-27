def solve_test_case():
    n = int(input())
    a = list(map(int, input().split()))
    res = [0] * n  

    mex = n
    for i in range(n - 1, -1, -1):
        res[i] = mex - a[i]
        mex = min(mex, mex - a[i])

    print(" ".join(map(str, res)))

def main():
    t = int(input())
    for _ in range(t):
        solve_test_case()

if __name__ == "__main__":
    main()
