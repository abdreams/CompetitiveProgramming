def slv(dp, pairs, mask, idx, n):
    if mask == 0:
        return 0
    if idx != -1 and dp[idx][mask] != -1:
        return dp[idx][mask]

    first_a, first_b = -1, -1
    if idx != -1:
        first_a = pairs[idx][0]
        first_b = pairs[idx][1]

    mxpr = 0
    for i in range(n):
        if mask & (1 << i):
            if idx == -1 or (pairs[i][0] == first_a or pairs[i][1] == first_b):
                mxpr = max(mxpr, 1 + slv(dp, pairs, (mask ^ (1 << i)), i, n))

    if idx == -1:
        return mxpr
    dp[idx][mask] = mxpr
    return mxpr

def read_input_and_calculate():
    num_pairs = int(input())
    pair_frequency = {}
    pairs = []
    for _ in range(num_pairs):
        a, b = input().split()
        pairs.append([a, b])
        pair_frequency[a] = pair_frequency.get(a, 0) + 1
        pair_frequency[b] = pair_frequency.get(b, 0) + 1

    mapping = {}
    num = 1
    for key, value in pair_frequency.items():
        mapping[key] = num
        num += 1
    mapped_pairs = [[0, 0] for _ in range(num_pairs)]
    for i in range(num_pairs):
        mapped_pairs[i][0] = mapping[pairs[i][0]]
        mapped_pairs[i][1] = mapping[pairs[i][1]]

    maximum_non_intersecting_pairs = 0
    mask = (1 << num_pairs) - 1
    dp = [[-1] * (mask + 1) for _ in range(num_pairs + 1)]

    maximum_non_intersecting_pairs = num_pairs - slv(dp, mapped_pairs, mask, -1, num_pairs)

    print(maximum_non_intersecting_pairs)

def main():
    num_test_cases = int(input())
    for _ in range(num_test_cases):
        read_input_and_calculate()

if __name__ == "__main__":
    main()
