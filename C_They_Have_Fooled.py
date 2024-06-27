def calculate_output(n):
    if n == 0 or n == 1:
        return 10
    elif n % 2 == 0:
        return 10
    elif n == 5:
        return n+2
    else:
        return 9 - n

n = int(input())
print(calculate_output(n))
