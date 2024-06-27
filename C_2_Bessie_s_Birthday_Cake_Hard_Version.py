def solve():
    n, x, y = map(int, input().split())
    inparr = list(map(int, input().split()))
    inparr = [(a-1)%n for a in inparr]
    inparr.sort()

    odd_ka_frk= []
    eve_ka_frk = []
    for i in range(x):
        if ((inparr[(i+1)%x]-inparr[i]+n)%n)>2:
            bekar=((inparr[(i+1)%x]-inparr[i]+n)%n)-1
            if bekar%2==0:
                eve_ka_frk.append(bekar)
            else:
                odd_ka_frk.append(bekar)

    odd_ka_frk.sort()
    z = n

    for x in odd_ka_frk:
        if y < x // 2:
            a = min(y, x // 2)
            x -= 2 * a
            z -= x
            y -= a
        else:
            y -= x // 2
            x = 0


    for x in eve_ka_frk:
        a = min(y,x//2)
        y -= a
        x -= 2*a
        z -= x

    print(z-2)


def main():
    T = int(input())
    for _ in range(T):
        solve()


if __name__ == "__main__":
    main()
