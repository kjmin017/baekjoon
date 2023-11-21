
def solve_linear_equations(a, b, c, d, e, f):
    
    determinant = a * e - b * d

    
    if determinant == 0:
        return "No unique solution exists."
    else:
        i = (e * c - b * f) / determinant
        j = (a * f - d * c) / determinant
        return i, j

a, b, c, d, e, f = map(int, input().split())

i, j = solve_linear_equations(a, b, c, d, e, f)
print(int(i), int(j))