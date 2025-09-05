def inverse_2x2(matrix: list[list[float]]) -> list[list[float]]:
    a, b, c, d = matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]
    det = a*d-b*c
    if det == 0:
        return None
    
    inverse = [[d/det, -b/det], [-c/det, a/det]]
    return inverse

print(inverse_2x2(matrix = [[4, 7], [2, 6]]))