# 불량 사용자
# https://programmers.co.kr/learn/courses/30/lessons/64064

from itertools import permutations

def solution(user_id, banned_id):
    ans_list = []

    def Check(user, ban):
        if len(user) != len(ban):
            return False
        for w in range(len(user)):
            if ban[w] != '*' and user[w] != ban[w]:
                return False
        return True

    for user_list in list(permutations(user_id, len(banned_id))):
        result = True
        for i, user in enumerate(user_list):
            result &= Check(user, banned_id[i])

        if result and set(user_list) not in ans_list:
            ans_list.append(set(user_list))

    return len(ans_list)

print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "abc1**"]))	#2
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["*rodo", "*rodo", "******"]))	#2
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "*rodo", "******", "******"]))	#3
# print(solution(["frodo", "froda", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "fr*d*", "*rodo", "******", "******"]))	#3