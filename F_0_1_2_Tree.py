import math

def min_height_tree(a, b, c):
    # Total number of vertices
    total_vertices = a + b + c
    
    # Calculate the minimum number of levels needed
    min_levels = math.ceil(math.log2(total_vertices + 1))
    
    # If there are not enough levels to distribute the vertices, return -1
    if min_levels < 2:
        return -1
    
    # Calculate the maximum number of vertices with 2 children on each level
    max_vertices_2_children = 2 ** (min_levels - 1) - 1
    
    # Calculate the maximum number of vertices with 1 child on each level
    max_vertices_1_child = min(total_vertices - max_vertices_2_children, max_vertices_2_children)
    
    # Calculate the remaining vertices
    remaining_vertices = total_vertices - max_vertices_2_children - max_vertices_1_child
    
    # Calculate the height of the tree
    height = min_levels + remaining_vertices
    
    return height

# Input number of test cases
t = int(input())

# Iterate through each test case
for _ in range(t):
    # Input a, b, c
    a, b, c = map(int, input().split())
    
    # Calculate and print the minimum height of the tree
    print(min_height_tree(a, b, c))
