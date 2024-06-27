from functools import cmp_to_key
from typing import *

inf = float('inf')


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input().strip()
        left = [0, 0]
        right = [0, 0]

        for i in range(n):
            if s[i] == '0':
                right[0] += 1
            else:
                right[1] += 1

        ans = -1
        val = float('inf')

        if (n // 2) + (n % 2) <= right[1]:
            val = n
            ans = 0

        for i in range(n):
            if s[i] == '0':
                right[0] -= 1
                left[0] += 1
            else:
                right[1] -= 1
                left[1] += 1

            left_cnt = left[0] + left[1]
            right_cnt = right[0] + right[1]

            if (left_cnt // 2) + (left_cnt % 2) <= left[0] and (right_cnt // 2) + (right_cnt % 2) <= right[1]:
                hue = abs(right_cnt - left_cnt)
                if hue < val:
                    val = hue
                    ans = i + 1

        print(ans)


if __name__ == "__main__":
    main()
