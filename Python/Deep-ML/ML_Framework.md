# numpy

## **1. 배열 생성 함수**

### **기본 배열 생성**
- **`np.array()`**: 리스트나 튜플을 NumPy 배열로 변환
- **`np.zeros(shape)`**: 0으로 초기화된 배열 생성
- **`np.ones(shape)`**: 1로 초기화된 배열 생성
- **`np.empty(shape)`**: 초기화되지 않은 배열 생성 (메모리 효율적)

### **연속된 값 생성**
- **`np.arange(start, stop, step)`**: 정수 범위 배열 생성
- **`np.linspace(start, stop, num)`**: 균등 간격 실수 배열 생성
- **`np.logspace(start, stop, num)`**: 로그 스케일 배열 생성

```python
np.array([1, 2, 3, 4, 5])      # [1 2 3 4 5]
np.zeros((2, 3))               # 2x3 영행렬
np.arange(0, 10, 2)            # [0 2 4 6 8]
np.linspace(0, 1, 5)           # [0. 0.25 0.5 0.75 1.]
```

## **2. 수학 함수**

### **기본 산술 연산**[2][3]
- **`np.add(a, b)`** 또는 **`a + b`**: 요소별 덧셈
- **`np.subtract(a, b)`** 또는 **`a - b`**: 요소별 뺄셈
- **`np.multiply(a, b)`** 또는 **`a * b`**: 요소별 곱셈
- **`np.divide(a, b)`** 또는 **`a / b`**: 요소별 나눗셈
- **`np.power(a, b)`** 또는 **`a ** b`**: 거듭제곱

### **삼각함수**[4][5]
- **`np.sin(x)`**, **`np.cos(x)`**, **`np.tan(x)`**: 삼각함수
- **`np.arcsin(x)`**, **`np.arccos(x)`**, **`np.arctan(x)`**: 역삼각함수

### **지수/로그 함수**[4]
- **`np.exp(x)`**: 자연지수 함수 (e^x)
- **`np.log(x)`**: 자연로그 (ln)
- **`np.log10(x)`**: 상용로그 (log₁₀)
- **`np.sqrt(x)`**: 제곱근

### **반올림 함수**[4]
- **`np.round(x, decimals)`**: 반올림
- **`np.floor(x)`**: 내림 (가장 가까운 작은 정수)
- **`np.ceil(x)`**: 올림 (가장 가까운 큰 정수)

```python
arr_a = np.array([1, 2, 3, 4])
arr_b = np.array([5, 6, 7, 8])
np.add(arr_a, arr_b)           # [6 8 10 12]
np.power(arr_a, 2)             # [1 4 9 16]
np.sqrt(np.array([1, 4, 9]))   # [1. 2. 3.]
```

## **3. 통계 함수**

### **기본 통계**[2]
- **`np.sum(arr, axis=None)`**: 합계
- **`np.mean(arr, axis=None)`**: 평균
- **`np.median(arr, axis=None)`**: 중앙값
- **`np.std(arr, axis=None)`**: 표준편차
- **`np.var(arr, axis=None)`**: 분산
- **`np.min(arr)`**, **`np.max(arr)`**: 최솟값, 최댓값

### **인덱스 반환 함수**
- **`np.argmin(arr)`**, **`np.argmax(arr)`**: 최솟값/최댓값의 인덱스
- **`np.argsort(arr)`**: 정렬된 인덱스

### **누적 함수**
- **`np.cumsum(arr)`**: 누적 합
- **`np.cumprod(arr)`**: 누적 곱

```python
data = np.array([[1, 2, 3], [4, 5, 6]])
np.sum(data)              # 21 (전체 합)
np.sum(data, axis=0)      # [5 7 9] (열별 합)
np.sum(data, axis=1)      # [6 15] (행별 합)
np.mean(data)             # 3.5
```

## **4. 배열 조작 함수**

### **형태 변경**[2]
- **`arr.reshape(shape)`**: 배열 모양 변경
- **`arr.flatten()`**: 1차원으로 변환 (복사본 생성)
- **`arr.ravel()`**: 1차원으로 변환 (가능하면 뷰 생성)
- **`arr.transpose()`** 또는 **`arr.T`**: 전치

### **배열 결합**[2]
- **`np.concatenate([arr1, arr2], axis=0)`**: 지정 축으로 결합
- **`np.vstack([arr1, arr2])`**: 수직 스택 (위아래 결합)
- **`np.hstack([arr1, arr2])`**: 수평 스택 (좌우 결합)
- **`np.stack([arr1, arr2], axis=0)`**: 새로운 축 생성하여 스택

### **배열 분할**
- **`np.split(arr, sections, axis=0)`**: 배열 분할
- **`np.hsplit(arr, sections)`**: 수평 분할
- **`np.vsplit(arr, sections)`**: 수직 분할

```python
original = np.arange(12).reshape(3, 4)
flattened = original.flatten()        # 1차원으로 변환
transposed = original.T               # 전치

arr1 = np.array([[1, 2], [3, 4]])
arr2 = np.array([[5, 6], [7, 8]])
np.vstack([arr1, arr2])               # 수직 결합
np.hstack([arr1, arr2])               # 수평 결합
```

## **5. 인덱싱 및 슬라이싱**

### **기본 인덱싱**[6]
- **`arr[index]`**: 단일 요소 접근
- **`arr[start:stop:step]`**: 슬라이싱
- **`arr[row, col]`**: 2차원 배열 인덱싱

### **고급 인덱싱**
- **불린 인덱싱**: `arr[arr > 5]` (조건을 만족하는 요소들)
- **`np.where(condition, x, y)`**: 조건에 따른 값 선택

```python
arr = np.array([1, 2, 3, 4, 5, 6])
arr[arr > 3]                         # [4 5 6] (조건 만족 요소)
np.where(arr > 3, arr, 0)            # [0 0 0 4 5 6]

arr_2d = np.array([[1, 2, 3], [4, 5, 6]])
arr_2d[0, :]                         # [1 2 3] (첫 번째 행)
arr_2d[:, 1]                         # [2 5] (두 번째 열)
```

## **6. 선형대수 함수**

### **행렬 연산**
- **`np.dot(A, B)`** 또는 **`A @ B`**: 행렬 곱셈
- **`np.linalg.det(A)`**: 행렬식
- **`np.linalg.inv(A)`**: 역행렬
- **`np.linalg.eig(A)`**: 고유값과 고유벡터

### **분해 함수**
- **`np.linalg.svd(A)`**: 특이값 분해 (SVD)
- **`np.linalg.qr(A)`**: QR 분해
- **`np.linalg.norm(A)`**: 노름 계산

```python
A = np.array([[1, 2], [3, 4]])
B = np.array([[5, 6], [7, 8]])
np.dot(A, B)                         # 행렬 곱셈
np.linalg.det(A)                     # 행렬식: -2.0
eigenvals, eigenvecs = np.linalg.eig(A)  # 고유값, 고유벡터
```

## **7. 랜덤 함수**

### **기본 랜덤 생성**
- **`np.random.random(size)`**: 0-1 사이 균등분포
- **`np.random.randint(low, high, size)`**: 정수 랜덤
- **`np.random.normal(loc, scale, size)`**: 정규분포
- **`np.random.uniform(low, high, size)`**: 균등분포

### **배열 조작**
- **`np.random.shuffle(arr)`**: 배열 섞기 (in-place)
- **`np.random.choice(arr, size)`**: 랜덤 선택
- **`np.random.seed(value)`**: 랜덤 시드 설정

```python
np.random.seed(42)                   # 재현 가능한 랜덤
np.random.random(5)                  # [0.37454012 ...]
np.random.randint(1, 10, 5)          # [3 7 8 5 4]
np.random.normal(0, 1, 5)            # 표준정규분포
```

## **8. 유틸리티 함수**

### **데이터 분석**
- **`np.unique(arr, return_counts=True)`**: 고유값과 개수
- **`np.sort(arr)`**: 정렬
- **`np.diff(arr, n=1)`**: 차분 계산

### **조건 및 검증**
- **`np.abs(arr)`**: 절댓값
- **`np.sign(arr)`**: 부호 (-1, 0, 1)
- **`np.isnan(arr)`**: NaN 체크
- **`np.isfinite(arr)`**: 유한값 체크
- **`np.clip(arr, min, max)`**: 값 범위 제한

```python
arr = np.array([3, 1, 4, 1, 5, 9, 2, 6])
np.sort(arr)                         # [1 1 2 3 4 5 6 9]
np.unique([1, 2, 2, 3], return_counts=True)  # ([1 2 3], [1 2 1])
np.clip([-2, -1, 0, 1, 2], -1, 1)   # [-1 -1 0 1 1]
```

## **코딩테스트 활용 팁**

### **자주 사용되는 패턴**
1. **데이터 전처리**: `reshape`, `concatenate`, `unique`
2. **통계 계산**: `mean`, `std`, `sum` (axis 파라미터 활용)
3. **조건 필터링**: 불린 인덱싱, `where` 함수
4. **행렬 연산**: `dot`, `transpose`, 선형대수 함수들
5. **랜덤 데이터**: `random` 모듈 함수들
