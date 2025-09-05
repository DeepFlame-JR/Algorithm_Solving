

def calculate_eigenvalues(matrix: list[list[float|int]]) -> list[float]:
    m1, m2, m3, m4 = matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]
    
    b = m1+m4
    c = m1*m4-m2*m3
    
    # 근의 공식
    e1 = (b + (b**2-4*c)**0.5)/2
    e2 = (b - (b**2-4*c)**0.5)/2
    return [e1,e2]


print(calculate_eigenvalues([[2, 1], [1, 2]]))