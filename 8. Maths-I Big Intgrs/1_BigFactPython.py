
#python me big number ka kalesh nahi hai

def fact(n):
    ans=1
    for i in range(1,n+1):
        ans=ans*i

    return ans

n=int(input())
print(fact(n))
