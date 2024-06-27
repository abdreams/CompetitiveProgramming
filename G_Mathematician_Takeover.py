import math

def mathematician_takeover(x):
    # Calculate the square root of x
    sqrt_x = math.sqrt(x)
    
    # Calculate the reciprocal of the square root
    reciprocal_sqrt_x = 1 / sqrt_x
    
    # Round the reciprocal to five decimal places
    rounded_reciprocal = round(reciprocal_sqrt_x, 5)
    
    return rounded_reciprocal

# Read the input
x = float(input())

# Calculate and print the result
print(mathematician_takeover(x))
