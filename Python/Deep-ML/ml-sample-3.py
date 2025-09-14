def linear_regression_step(x_vals, y_vals, w, b, lr):
    """
    x_vals: list of x values
    y_vals: list of y values
    w, b: current parameters
    lr: learning rate
    Returns: (w_new, b_new)
    """
    # implement this
    # 1. 예측값 y_hat 리스트 생성
    y_hat = [0] * len(x_vals)
    for i in range(len(x_vals)):
        y_hat[i] = w*x_vals[i] + b
        
    print(y_hat)
    
    # 2. 기울기 계산: dw = (1/N) * Σ (y_hat - y) * x_i
    #                   db = (1/N) * Σ (y_hat - y)
    smw = 0
    for i in range(len(x_vals)):
        smw += (y_hat[i]-y_vals[i])*x_vals[i]
    dw = smw / len(x_vals)

    smb = 0
    for i in range(len(x_vals)):
        smb += (y_hat[i] - y_vals[i])
    db = smb / len(x_vals)
    
    # 3. 파라미터 업데이트: w_new = w - lr * dw, b_new = b - lr * db
    w_new = w - lr * dw
    b_new = b - lr * db
    return w_new, b_new

x_vals = [1.0, 2.0, 3.0]
y_vals = [2.0, 4.0, 6.0]
w, b = 0.0, 0.0
lr = 0.1

w_new, b_new = linear_regression_step(x_vals, y_vals, w, b, lr)
print(w_new, b_new)
# 출력 예시: (0.44, 0.2)