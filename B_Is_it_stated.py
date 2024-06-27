t = int(input())

for _ in range(t):
    s=input()

    cnt=0
    for i in range(len(s)-1):
        if s[i]=='i' and s[i + 1]=='t':
            cnt+=1

    if cnt>0:
        print("YES")
    else:
        print("NO")
