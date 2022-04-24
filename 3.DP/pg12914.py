# 멀리뛰기
# https://programmers.co.kr/learn/courses/30/lessons/12914

def solution(n):
    arr = [1, 2]
    if n <= 2:
        return arr[n-1]

    for i in range(2, n):
        arr.append(arr[i - 1] + arr[i - 2])

    return arr[n - 1]

print(solution(1))
print(solution(2))
print(solution(3))
print(solution(4))
print(solution(5))
print(solution(6))

'''
1: [1]
2: [1,1], [2]
3: [1,1,1], [1,2], [2,1]

4를 구해보자. 
4 = 1+3 = 2+2 이다.
-> (처음에 1으로 시작하는 경우의 수) = (3의 경우의 수)
-> (처음에 2로 시작하는 경우의 수) = (2의 경우의 수)
'''