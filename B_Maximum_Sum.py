MOD = 10**9 + 7

def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))

        asum = sum(a)
        
        total_sum = 0
        maxi = 0
        for i in range(n):
            total_sum += a[i]
            if total_sum < 0:
                total_sum = 0
            maxi = max(maxi, total_sum)

        power = 1
        for i in range(k):
            power = (power * 2) % MOD

        ans = (maxi * (power - 1)) % MOD

        fin = (ans + asum) % MOD
        if fin < 0:
            fin += MOD

        print(fin)

if __name__ == "__main__":
    main()
