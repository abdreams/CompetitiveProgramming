def res():
    s1 = input().strip()
    s2 = input().strip()

    ans = len(s2)
    
    for s in range(len(s2)):
        curr = s
        i2 = s
        for i1 in range(len(s1)):
            if i1 < len(s1) and s1[i1] == s2[i2]:
                i2 += 1
                if i2 == len(s2):
                    break
        ans = min(ans, curr + len(s2) - i2)
    
    print(ans + len(s1))

def main():
    t = int(input().strip())
    for _ in range(t):
        res()

if __name__ == "__main__":
    main()
