N, S = list(map(int, input().split()))
arr = list(map(int, input().split()))

result = 987654321

total = 0
left = 0
for right in range(N):
    total += arr[right]

    if total >= S:
        while left <= right:
            if total < S:
                break
            result = min(result, right-left+1)
            total -= arr[left]
            left += 1

if result == 987654321:
    print(0)
else:
    print(result)