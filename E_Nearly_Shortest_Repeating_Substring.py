def shortest_repeating_substring(n, s):
    # Function to check if a given substring can be repeated to form the original string with at most one different character
    def is_valid_substring(sub):
        differences = 0
        for i in range(n):
            if s[i] != sub[i % len(sub)]:
                differences += 1
            if differences > 1:
                return False
        return True

    shortest_length = n  # Initialize with the length of the original string
    for length in range(1, n + 1):
        if n % length == 0:  # Check only lengths that can divide the length of the string
            substring = s[:length]
            if is_valid_substring(substring):
                shortest_length = min(shortest_length, length)

    return shortest_length

# Input
t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()

    # Output
    print(shortest_repeating_substring(n, s))
