# 표 편집
# https://programmers.co.kr/learn/courses/30/lessons/81303

from collections import deque
def solution(n, k, cmd):
    def Up(position, distance):
        while distance > 0:
            position -= 1
            if table[position] == 'O':
                distance -= 1
        return position

    def Down(position, distance):
        while distance > 0:
            position += 1
            if table[position] == 'O':
                distance -= 1
        return position

    def Can_Down(position):
        while position < n - 1:
            position += 1
            if table[position] == 'O':
                return position
        return -1

    # initialize
    table = dict()
    for i in range(n):
        table[i] = 'O'

    queue = deque()
    cur = k
    for c in cmd:
        actions = c.split(' ')
        if actions[0] == 'U':
            cur = Up(cur, int(actions[1]))
        elif actions[0] == 'D':
            cur = Down(cur, int(actions[1]))
        elif actions[0] == 'C':
            table[cur] = 'X'
            queue.append(cur)
            t = Can_Down(cur)
            if t > 0:
                cur = t
            else:
                cur = Up(cur, 1)
        elif actions[0] == 'Z':
            table[queue.pop()] = 'O'

    ans = ''.join(list(table.values()))
    return ans



from collections import deque
def solution(n, k, cmd):
    table = dict()
    for i in range(n):
        table[i] = [i-1, i+1]
    table[n-1][1] = -1

    queue = deque()
    cur = k
    for c in cmd:
        actions = c.split(' ')
        if actions[0] == 'U':
            for _ in range(int(actions[1])):
                cur = table[cur][0]
        elif actions[0] == 'D':
            for _ in range(int(actions[1])):
                cur = table[cur][1]
        elif actions[0] == 'C':
            queue.append((table[cur][0], cur, table[cur][1]))
            left, right = table[cur]

            if left == -1:
                table[right][0] = -1
            elif right == -1:
                table[left][1] = -1
            else:
                table[left][1], table[right][0] = right, left
            # 이동
            if right == -1:
                cur = left
            else:
                cur = right

        elif actions[0] == 'Z':
            left, restore, right = queue.pop()
            if right == -1:
                table[left][1] = restore
            elif left == -1:
                table[right][0] = restore
            else:
                table[left][1], table[right][0] = restore, restore
    ans = ['O' for _ in range(n)]
    while queue:
        ans[queue.pop()[1]] = 'X'
    return ''.join(ans)


a = solution(5,2,["C","C","Z","U 1","U 1","U 1"])
