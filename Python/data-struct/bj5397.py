N = int(input())

for _ in range(N):
    setence = input()
    
    front = []
    back = []
    for char in setence:
        if char == "<":
            if len(front) > 0:
                back.append(front.pop())
        elif char == ">":
            if len(back) > 0:
                front.append(back.pop())
        elif char == "-":
            if len(front) > 0:
                front.pop()
        else:
            front.append(char)
    
    result = front+back[::-1]
    print("".join(result))
            