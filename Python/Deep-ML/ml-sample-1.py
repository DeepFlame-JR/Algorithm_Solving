import math

def entropy(labels):
    counts = {}
    for l in labels:
        counts[l] = counts.get(l, 0) + 1
    total = len(labels)
    ent = 0.0
    for c in counts.values():
        p = c / total
        ent -= p * math.log2(p)
    return ent

def information_gain(data, feature_idx, threshold):
    """
    data: 2D list, 각 행은 [x, y, label]
    feature_idx: 0 또는 1 (x1 또는 y1)
    threshold: 분할 값
    """
    # 1. 전체 엔트로피 계산
    labels = [d[-1] for d in data]
    ent = entropy(labels)
    
    # 2. 분할 후 좌/우 엔트로피 및 가중 평균 계산
    left_labels = []
    right_labels = []
    for row in data:
        featured_data = row[feature_idx]
        if featured_data <= threshold:
            left_labels.append(row[-1])
        else:
            right_labels.append(row[-1])
    
    left_ent = entropy(left_labels)
    right_ent = entropy(right_labels)
    
    
    # 3. 정보 이득 = 전체 엔트로피 - 가중 평균 엔트로피
    ans = ent - (left_ent/2 + right_ent/2)
    return ans


data = [
    [2.7, 1.0, 0],
    [1.3, 3.5, 1],
    [3.0, 2.0, 0],
    [0.5, 4.2, 1]
]
feature_idx = 0
threshold = 2.0
print(information_gain(data, feature_idx, threshold))