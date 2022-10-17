# 보석쇼핑
# https://programmers.co.kr/learn/courses/30/lessons/67258

def solution(gems):
    N = len(gems)
    unique_count = len(set(gems))
    if unique_count == 1: return [1,1]

    gem_dict = {}
    for g in set(gems):
        gem_dict[g] = 0

    left = 0
    gem_count = 1
    gem_dict[gems[0]] += 1

    ans = [0,N-1]
    for right in range(1, N):
        gem = gems[right]
        gem_dict[gem] += 1
        if gem_dict[gem] == 1:
            gem_count += 1

        if gem_count == unique_count:
            ans = [left, right] if right - left < ans[1] - ans[0] else ans

            # move left point
            while left < right:
                gem = gems[left]
                if gem_dict[gem] == 1:
                    break

                gem_dict[gem] -= 1
                left += 1
                ans = [left, right] if right - left < ans[1] - ans[0] else ans

        # print(left, right, ans)
    return list(map(lambda x:x+1, ans))

print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))	#[3, 7]
print(solution(["AA", "AB", "AC", "AA", "AC"]))	#[1, 3]
print(solution(["XYZ", "XYZ", "XYZ"]))	#[1, 1]
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))	#[1, 5]
print(solution(['a','b','b','c','b','a']))