# 경주로 건설
# https://programmers.co.kr/learn/courses/30/lessons/67259

import numpy as np

import heapq
def solution(board):
    N = len(board)
    Visit1 = [[float('inf') for r in range(N)] for c in range(N)]
    Visit2 = [[float('inf') for r in range(N)] for c in range(N)]

    ans = float('inf')
    heap = []
    heapq.heappush(heap, (0,0,0,0))
    heapq.heappush(heap, (0,0,0,1))
    Visit1[0][0] = 0
    Visit2[0][0] = 0

    while heap:
        cur_w, cur_x, cur_y, cur_updown = heapq.heappop(heap)

        if cur_x == N-1 and cur_y == N-1:
            ans = min(cur_w, ans)

        for i, (dx, dy) in enumerate(((1,0), (-1,0), (0,-1), (0,1))):
            updown = i//2
            w = 100 if updown == cur_updown else 600
            nx, ny = cur_x + dx, cur_y + dy

            if 0<=nx<N and 0<=ny<N and board[nx][ny] == 0:
                if updown == 0 and cur_w+w < Visit1[nx][ny]:
                    Visit1[nx][ny] = cur_w + w
                    heapq.heappush(heap, (cur_w + w, nx, ny, updown))
                elif updown == 1 and cur_w+w < Visit2[nx][ny]:
                    Visit2[nx][ny] = cur_w + w
                    heapq.heappush(heap, (cur_w + w, nx, ny, updown))
    return ans


print(solution([[0,0,0],[0,0,0],[0,0,0]]))
print(solution([[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]))
print(solution([[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]))
print(solution([[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]]))
