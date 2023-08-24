# Problem Name: Evaluating functions
# Problem Difficulty: None
# Problem Constraints: 0<=x<=10^50
# Problem Description:
# Alice is learning mathematical functions. In his assignment, teacher has asked him to evaluate h(x)= f(x)+g(x) where <br>f(x)=3x<sup>2</sup>-x+10 and <br> g(x)=4x<sup>3</sup>+2x<sup>2</sup>-5x+4.<br> As he is weak in mathematics, help him finish this task.

# Hint: Since X is large, you need to work with Big Integers!

# Input Format: Single line containing an integral value denoting the value of x.
# Sample Input: 1
# Output Format: Print integral value denoting value of h(x).
# Sample Output: 17

def f(x):
    return 3*x**2 - x + 10

def g(x):
    return 4*x**3 + 2*x**2 - 5*x + 4

def h(x):
    return f(x) + g(x)

x = int(input())
result = h(x)
print(result)
