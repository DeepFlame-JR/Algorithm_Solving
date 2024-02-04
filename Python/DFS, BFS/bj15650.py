N, M = list(map(int, input().split(' ')))

Visit = [0]*(N+1)

def DFS(n):
    if sum(Visit) == M:
        for i in range(1, N+1):
            if Visit[i] == 1:
                print(i, end=" ")
        print()
        return

    for i in range(n, N+1):
        Visit[i] = 1 
        DFS(i+1)
        Visit[i] = 0
        
DFS(1)