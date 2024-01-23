import queue

pq = queue.PriorityQueue()


if __name__ == "__main__":
    N = int(input())
    for _ in range(N):
        pq.put(int(input()))
    
    result = 0
    while pq.qsize() > 1:
        a = pq.get()
        b = pq.get()
        total = a+b
        result += total
        pq.put(total)
    
    print(result)
    

