def main():
    num_tests = int(input())
    for _ in range(num_tests):
        n, x, y = map(int, input().split())
        array = list(map(int, input().split()))
        array.sort()
        answer = x - 2
        last_element_plus_two = array[x - 1] + 2
        for i in range(x - 1):
            if array[i] + 2 == array[i + 1]:
                answer += 1
        if x >= 2 and last_element_plus_two % n == array[0]:
            answer += 1
        print(answer)

if __name__ == "__main__":
    main()
