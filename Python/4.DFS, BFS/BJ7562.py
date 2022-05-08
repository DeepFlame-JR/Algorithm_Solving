import sys
from collections import deque

global Visit
dir_n1 = [-1, -2, -2, -1, 1, 2, 2, 1]
dir_n2 = [-2, -1, 1, 2, 2, 1, -1, -2]

def Check(n1, n2) :
    if n1 < 1 or n1 > N or n2 < 1 or n2 > N or Visit[n1][n2] == 1:
        return False
    return True

if __name__ == '__main__' :
    T = int(input())

    for _ in range(T) :
        N = int(input())
        Visit = [[0]*(N+1) for _ in range(N+1)]

        n1, n2 = map(int, sys.stdin.readline().split())
        d1, d2 = map(int, sys.stdin.readline().split())

        Queue = deque()
        Queue.append((n1+1, n2+1, 0))

        while Queue :
            cur = Queue.popleft()
            if cur[0] == d1+1 and cur[1] == d2+1 :
                print(cur[2])
                break

            for i in range(8) :
                next_n1 = cur[0] + dir_n1[i]
                next_n2 = cur[1] + dir_n2[i]
                if Check(next_n1, next_n2) :
                    Visit[next_n1][next_n2] = 1
                    Queue.append((next_n1, next_n2, cur[2] + 1))
