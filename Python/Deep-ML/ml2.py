# https://www.deep-ml.com/problems/2

def transpose_matrix(a: list[list[int|float]]) -> list[list[int|float]]:
    b = []
    for i in range(len(a[0])):
        b.append([])
    
    for row in a:
        for i in range(len(row)):
            b[i].append(row[i])
    return b


print(transpose_matrix([[1,2,3],[4,5,6]]))