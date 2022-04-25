# 합승 택시 요금
# https://programmers.co.kr/learn/courses/30/lessons/72413

import heapq
def solution(N, S, A, B, fares):
    E = [[] for _ in range(N+1)]

    for fare in fares:
        p1, p2, weight = fare
        E[p1].append([p2, weight])
        E[p2].append([p1, weight])

    def dijkstra(start, end, weight):
        q = []
        w_list = [float('inf') for _ in range(N+1)]
        heapq.heappush(q, (weight, start))
        while q:
            weight, cur = heapq.heappop(q)
            if weight > ans:
                return None
            if cur == end:
                return weight
            for next, next_w in E[cur]:
                if weight + next_w < w_list[next]:
                    w_list[next] = weight + next_w
                    heapq.heappush(q, (weight + next_w, next))

    ans = float('inf')
    Visit = [False for _ in range(N+1)]
    start_q = []
    heapq.heappush(start_q, (0, S))
    while start_q:
        start_w, start = heapq.heappop(start_q)
        Visit[start] = True

        a = dijkstra(start, A, start_w)
        b = dijkstra(start, B, start_w)
        if not a or not b:
            continue
        print(start, start_w, a, b, a+b-start_w)

        ans = min(ans, a+b-start_w)

        for next, next_w in E[start]:
            if not Visit[next]:
                heapq.heappush(start_q, (start_w+next_w, next))

    return ans


a1 = solution(7,3,4,1,[[5, 7, 9], [4, 6, 4], [3, 6, 1], [3, 2, 3], [2, 1, 6]])
a2 = solution(6,4,5,6,[[2,6,6], [6,3,7], [4,6,7], [6,5,11], [2,5,12], [5,3,20], [2,4,8], [4,3,9]])
a3 = solution(6,4,6,2,[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]])
print(a1, a2, a3)

