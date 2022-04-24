import sys
from collections import deque

N, M, V = 0, 0, 0
Edge, Visit = [], []

def BFS(start) :
    Queue = deque()

    print(start, end=" ")
    Visit[start] = 1
    Queue.append(start)

    while Queue :
        cur = Queue.popleft()
        for i in Edge[cur]:
            if cur == i :
                continue

            if Visit[i] == 0 and i in Edge[cur]:
                print(i, end=" ")
                Visit[i] = 1
                Queue.append(i)

def DFS(cur) :
    print(cur, end=" ")
    Visit[cur] = 1
    for i in Edge[cur] :
        if cur == i :
            continue

        if Visit[i] == 0 and i in Edge[cur]:
            DFS(i)

if __name__ == '__main__' :
    N, M, V = map(int, sys.stdin.readline().split())
    N += 1
    Edge = [[] for _ in range(N)]

    for _ in range(M) :
        n1, n2 = map(int, sys.stdin.readline().split())
        Edge[n1].append(n2)
        Edge[n2].append(n1)

    for e in Edge :
        e.sort()

    Visit = [0]*N
    DFS(V)

    Visit = [0]*N
    BFS(V)
