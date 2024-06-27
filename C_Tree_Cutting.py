from collections import defaultdict

def f(x, n, k):
    return n // (k + 1) >= x

def main():
    tc = int(input())
    for _ in range(tc):
        n, k = map(int, input().split())
        
        adj = defaultdict(list)
        
        for _ in range(n - 1):
            u, v = map(int, input().split())
            u -= 1
            v -= 1
            adj[u].append(v)
            adj[v].append(u)
        
        lo, hi = 1, int(1e9)
        
        while hi - lo > 1:
            mid = (lo + hi) // 2
            if f(mid, n, k):
                lo = mid
            else:
                hi = mid
        
        print(lo)

if __name__ == "__main__":
    main()