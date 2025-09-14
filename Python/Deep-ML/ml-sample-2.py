def perceptron_predict(x, weights, bias):
    """
    x: 1D list of input 특성 값 [x1, x2, ..., xn]
    weights: 1D list 가중치 [w1, w2, ..., wn]
    bias: 편향 값 (float)
    
    Returns: 출력 0 또는 1
    """
    # implement this
    # 1. 가중합 계산: z = sum(w_i * x_i) + bias
    sm = 0
    for i in range(len(x)):
        sm += x[i] + weights[i] 
    sm += bias
    
    # 2. 계단 함수 적용: output = 1 if z >= 0 else 0
    return 1 if sm >= 0 else 0


x = [2.0, -1.0, 0.5]
weights = [0.4, -0.2, 0.1]
bias = -0.1
print(perceptron_predict(x, weights,bias))