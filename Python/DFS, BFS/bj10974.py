N = int(input())

def perm(arr:list, n:int) -> list[list]:
    if n == 0:
        return [[]]
    result = []
    
    for i in range(len(arr)):
        for rest in perm(arr[:i] + arr[i+1:], n-1):
            result.append([arr[i]] + rest)
    return result

arr = [n for n in range(1, N+1)]
for ans in perm(arr, len(arr)):
    print(*ans, sep=" ")
    
    