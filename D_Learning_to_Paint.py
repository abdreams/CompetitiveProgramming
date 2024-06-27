import heapq

def solve_test_case(n, k, beauty_grid):
    max_beauties_heap = []

    prefix_sums = [[0] * (n+1) for _ in range(n)]
    for i in range(n):
        for j in range(n):
            prefix_sums[i][j+1] = prefix_sums[i][j] + beauty_grid[i][j]

    for i in range(n):
        for j in range(i, n):
            beauty = sum(prefix_sums[j][j+1] - prefix_sums[j][i] for j in range(i, j+1))
            heapq.heappush(max_beauties_heap, -beauty)
            if len(max_beauties_heap) > k:
                heapq.heappop(max_beauties_heap)

    result = []
    while max_beauties_heap:
        result.append(-heapq.heappop(max_beauties_heap))
    result.reverse()
    print(*result)

def main():
    t = int(input())

    for _ in range(t):
        n, k = map(int, input().split())
        beauty_grid = []

        for _ in range(n):
            beauty_grid.append(list(map(int, input().split())))

        solve_test_case(n, k, beauty_grid)

if __name__ == "__main__":
    main()
