def solve_test_case(n, x, permutation):
    if permutation[0] == x:
        return 0, []

    x_index = permutation.index(x)
    
    if x_index != 0:
        operations = [[1, x_index + 1]]
        permutation[0], permutation[x_index] = permutation[x_index], permutation[0]
    
    l, r = 1, n + 1
    while r - l > 1:
        m = (r + l) // 2
        if permutation[m - 1] <= x:
            l = m
        else:
            r = m
    
    operations_needed = 0
    swaps = []
    if permutation[l - 1] != x:
        operations_needed = 2
        swaps.append([l, l - 1])
        swaps.append([1, l])
    
    return operations_needed, swaps

t = int(input())

for _ in range(t):
    n, x = map(int, input().split())
    permutation = list(map(int, input().split()))
    # Solve the test case
    operations, swaps = solve_test_case(n, x, permutation)
    # Output the number of operations and the swaps
    print(operations)
    for swap in swaps:
        print(*swap)
