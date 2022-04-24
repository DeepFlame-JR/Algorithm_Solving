# 셔틀버스
# https://programmers.co.kr/learn/courses/30/lessons/17678

def solution(n, t, m, timetable):
    def get_ans(t):
        return "%02d:%02d" %(t//60, t%60)
    N, T, M = n, t, m
    Last_Time = (N-1)*T + 540 # 막차시간
    table = []

    for time in timetable:
        h, m = time.split(':')
        t = int(h)*60+int(m)
        if t <= Last_Time:
            table.append(t)
    if len(table) == 0:
        return get_ans(Last_Time)

    table.sort()
    L = len(table)
    time = 540 - T
    left = 0
    n = N
    while left < L:
        n -= 1 # 버스 출발
        time += T # 시간
        if n == 0: # 막차 입니다.
            temp = table[left: left+M]
            if len(temp) == M:
                return get_ans(temp[-1]-1)
            else:
                return get_ans(Last_Time)

        for _ in range(M):
            if left < L and table[left] <= time:
                left += 1
            else:
                break

    return get_ans(Last_Time)


print(solution(1,1,5,["08:00", "08:01", "08:02", "08:03"])) # "09:00"
print(solution(2,10,2,["09:10", "09:09", "08:00"])) #"09:09"
print(solution(2,1,2,["09:00", "09:00", "09:00", "09:00"])) # "08:59"
print(solution(1,1,5,["00:01", "00:01", "00:01", "00:01", "00:01"])) # "00:00"
print(solution(1,1,1,["23:59"])) # "09:00"
print(solution(10,60,45,["23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"])) #"18:00