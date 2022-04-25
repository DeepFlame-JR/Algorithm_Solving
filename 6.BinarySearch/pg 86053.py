# 금과 은 운반하기
# https://programmers.co.kr/learn/courses/30/lessons/86053

def solution(a, b, g, s, w, t):
    ans = 10**5 * 10**9 * 4
    right = ans
    left = 0
    N = len(g)

    while left <= right:
        mid = (left+right)//2
        G, S, T = 0, 0, 0

        for i in range(N):
            gold, silver, weight, time = g[i], s[i], w[i], t[i]
            # 처음 편도
            move = min(mid//time, 1)
            # 왕복
            move += (mid-time)//(2*time)

            # 금,은 가져오기
            carry_gold = min(weight*move, gold)
            carry_silver = min(weight*move, silver)
            carry_total = min(weight*move, gold+silver)

            G, S, T = G+carry_gold, S+carry_silver, T+carry_total

        if G >= a and S >= b and T >= a+b:
            right = mid-1
            ans = min(ans, mid)
        else:
            left = mid+1

    return ans

print(solution(10,10,[100],[100],[7],[10]))	# 50
print(solution(90,500,[70,70,0],[0,0,500],[100,100,2],[4,8,1])) #499