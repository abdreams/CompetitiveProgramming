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
        
        count_a = {1: 0, 0: 0, -1: 0}
        count_b = {1: 0, 0: 0, -1: 0}
        
        for i in range(n):
            count_a[a[i]] += 1
            count_b[b[i]] += 1
        
        ira = count_a[1] - count_a[-1]
        irb = count_b[1] - count_b[-1]
   
        tl = count_a[1] + count_b[1]
        td = count_a[-1] + count_b[-1]
        nt = count_a[0] + count_b[0]
        
        mini = abs((ira - irb) // 2)
        
        maxi = min(nt, mini)
        
        bra = ira - maxi
        brb = irb + maxi

        
        result = max(min(bra, brb),
                     min(ira, irb))
        
        results.append(result)
    
    sys.stdout.write("\n".join(map(str, results)) + "\n")

if __name__ == "__main__":
    solve()
