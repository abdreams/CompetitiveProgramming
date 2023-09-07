# Problem Name: Virat and Factorials
# Problem Difficulty: 
# Problem Constraints: 1<=N<=100
# Problem Description:
# Virat Kohli now wants to learn coding. So Dhoni gave him a simple task of calculating factorial of a number. Help him finish this task.

# Input Format: Single line containing an integral value N.
# Sample Input: 3
# Output Format: Print the integral value denoting factorial of 'N'.
# Sample Output: 6

def calculate_factorial(n):
    if n == 0:
        return 1
    else:
        factorial = 1
        for i in range(1, n + 1):
            factorial *= i
        return factorial

n = int(input())

result = calculate_factorial(n)
print(result)
