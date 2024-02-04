from queue import PriorityQueue

N = int(input())
arr = [0] + list(map(int, input().split()))
result = [0]*(N+1)

stk = []
pq = PriorityQueue()

for i in range(1, N+1):
    stk.append((arr[i], i))
    
while len(stk) > 0:
    cur = stk.pop()
    while not pq.empty():
        if pq.queue[0][0] < cur[0]:
            top = pq.get()
            result[top[1]] = cur[1]
        else:
            break
    pq.put(cur)
    

print(*result[1:], sep=" ")
