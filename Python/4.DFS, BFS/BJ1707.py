import sys
from collections import deque

global Edge, Visit

def BFS(start) :
    Queue = deque()
    Queue.append((start, 1))
    Visit[start] = 1

    while Queue :
        cur = Queue.popleft()

        for next in Edge[cur[0]] :
            if(Visit[next] == cur[1]) :
                return False

            if(Visit[next] == 0) :
                Queue.append((next, -cur[1]))
                Visit[next] = -cur[1]
    return True

if __name__ == '__main__' :
    T = int(input())

    for t in range(T) :
        V, E = map(int, sys.stdin.readline().split())
        Edge = [[] for _ in range(V+1)]
        Visit = [0] * (V+1)

        for _ in range(E) :
            t1, t2 = map(int, sys.stdin.readline().split())
            Edge[t1].append(t2)
            Edge[t2].append(t1)

        for e in Edge :
            e.sort()

        for cur in range(1, V+1) :
            if Visit[cur] == 0:
                plag = BFS(cur)
                if not plag :
                    break

        print("YES" if plag else "NO")
