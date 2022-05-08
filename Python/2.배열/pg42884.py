# 단속카메라
# https://programmers.co.kr/learn/courses/30/lessons/42884

def solution(routes):
    routes.sort(key = lambda x:(x[1],x[0]))
    # routes.sort(key = lambda x:x[1])
    # routes.sort(key = lambda x:x[0])
    print(routes)

    ans = 1
    end_point = routes[0][1]
    for i, route in enumerate(routes):
        if i == 0:
            continue

        # end_point 전에 출발함
        if route[0] <= end_point:
            # 그런데 먼저 나감? end_point 옮김
            if route[1] < end_point:
                end_point = route[1]
            continue

        # end_point 후에 출발 (새로 설치해야함)
        ans += 1
        end_point = route[1]

    print(ans)
    return ans

solution([[0,3],[1,2], [3,4]])
