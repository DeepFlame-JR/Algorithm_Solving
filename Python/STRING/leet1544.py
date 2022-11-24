def makeGood(s: str):
    from collections import deque

    stack = deque()
    diff = ord('a') - ord('A') 

    for ch in s:
        if len(stack) > 0 and abs(ord(stack[0])-ord(ch)) == diff:
            stack.popleft()
        else:
            stack.appendleft(ch)

    ans = ''
    while len(stack) > 0:
        ans += stack.pop()

    return ans

print(makeGood("leEeetcode"))