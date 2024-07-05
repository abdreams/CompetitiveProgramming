import heapq

def max_experience(n, m, a, b, c):
    gains = []
    for i in range(n):
        gains.append((a[i] - b[i], a[i], b[i]))
    

    heapq.heapify(gains)
    
    total_experience = 0
    
    while m > 0 and gains:
        net_gain, ai, bi = heapq.heappop(gains)
        
        craftable = min(m, c[0] // ai)
        
        total_experience += craftable
        
        c[0] -= craftable * ai
        c[0] += craftable * bi
        

        if craftable > 0:
            heapq.heappush(gains, (ai - bi, ai, bi))
        
        m -= craftable
    
    return total_experience

# 10 20 20 0 0 0 9 10 19



import sys
input = sys.stdin.read
data = input().split()
n = int(data[0])
m = int(data[1])
a = list(map(int, data[2:n+2]))
b = list(map(int, data[n+2:2*n+2]))
c = list(map(int, data[2*n+2:2*n+2+m]))


result = max_experience(n, m, a, b, c)
print(result)
