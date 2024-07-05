def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    t = int(data[idx])
    idx += 1
    results = []
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        
        a = list(map(int, data[idx:idx + n]))
        idx += n
        b = list(map(int, data[idx:idx + n]))
        idx += n
        
        P = 0  # Number of positive reviews (likes)
        N = 0  # Number of negative reviews (dislikes)
        
        for i in range(n):
            if a[i] == b[i]:
                if a[i] == -1:
                    N += 1
                elif a[i] == 1:
                    P += 1

        A = 0  # Rating of the first movie
        B = 0  # Rating of the second movie
        
        for i in range(n):
            if a[i] != b[i]:
                A += a[i]
                B += b[i]
        
        if A > B:
            A, B = B, A
        
        # Adjust ratings using positive reviews
        count = P
        x = min(B - A, count)
        A += x
        count -= x
        x = count // 2
        A += max(x, count)
        B += min(x, count)
        
        if A > B:
            A, B = B, A
        
        # Adjust ratings using negative reviews
        count = N
        x = max(A - B, count)
        B += x
        count -= x
        x = count // 2
        A += max(x, count)
        B += min(x, count)
        
        results.append(min(A, B))
    
    sys.stdout.write("\n".join(map(str, results)) + "\n")

if __name__ == "__main__":
    solve()
