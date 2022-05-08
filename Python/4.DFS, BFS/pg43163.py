# 단어 변환
# https://programmers.co.kr/learn/courses/30/lessons/43163

from collections import deque
def solution(begin, target, words):
    global ans

    if not target in words:
        return 0

    Visit = [0] * len(words)
    ans = float('inf')

    def Check(word, n_word):
        r = 0
        for i in range(len(word)):
            if word[i] != n_word[i]:
                r += 1
        return True if r == 1 else False

    def DFS(word, cum):
        global ans

        if word == target:
            ans = min(ans, cum)
            return

        for i, n_word in enumerate(words):
            if Visit[i] == 0 and Check(word, n_word) == 1:
                Visit[i] = 1
                DFS(n_word, cum + 1)
                Visit[i] = 0

    DFS(begin, 0)

    return ans if ans != float('inf') else 0

print(solution("hit","cog",["hot", "dot", "dog", "lot", "log", "cog"]))