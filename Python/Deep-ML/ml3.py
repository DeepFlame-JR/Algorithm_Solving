# https://www.deep-ml.com/problems/3

import numpy as np

def reshape_matrix(a: list[list[int|float]], new_shape: tuple[int, int]) -> list[list[int|float]]:
    if len(a) * len(a[0]) != new_shape[0] * new_shape[1]:
        return []
    return np.array(a).reshape(new_shape)

print(reshape_matrix([[1,2,3,4],[5,6,7,8]], (4,2)))
print(reshape_matrix([[1, 2, 3, 4], [5, 6, 7, 8]], (1, 4)))