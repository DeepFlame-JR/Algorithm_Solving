import sys
sys.setrecursionlimit(10**8)

T = int(input())

def DFS(idx):
    global result
    
    Visit[idx] = 1
    Cycle.append(idx)
    nxt = arr[idx]
    
    if Visit[nxt] == 1:
        if nxt in Cycle:
            result -= len(Cycle[Cycle.index(nxt):])  # 순환하는 것부터 계산
    else:
        DFS(nxt)    

                
for _ in range(T):
    N = int(input())
    arr = [0] + list(map(int, input().split()))
    Visit = [0] * (N+1)
    result = N
    
    for i in range(1, N+1):
        if Visit[i] == 0:
            Cycle = []
            DFS(i)
            
    print(result)