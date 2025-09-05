def calculate_matrix_mean(matrix: list[list[float]], mode: str) -> list[float]:
    means = []
    if mode == 'row':
        for row in matrix:
            means.append(sum(row)/len(row))
    elif mode == 'column':
        for j in range(len(matrix[0])):
            column_sum = 0
            for i in range(len(matrix)):
                column_sum += matrix[i][j]
            means.append(column_sum/len(matrix))
    return means


print(calculate_matrix_mean([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 'row'))
print(calculate_matrix_mean([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 'column'))
print(calculate_matrix_mean([[1, 2, 3, 4], [5, 6, 7, 8]], 'column'))
