#
# @lc app=leetcode id=967 lang=python3
#
# [967] Numbers With Same Consecutive Differences
#

# @lc code=start
class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        result = []
        
        def dfs(prev):
            if len(prev) == n:
                result.append(int(prev))
                return
            
            last_number = int(prev[-1])
            if last_number + k < 10:
                dfs(prev + str(last_number+k))
            if k == 0:
                return
            if last_number - k >= 0:
                dfs(prev + str(last_number-k))
        
        for i in range(1,10):
            dfs(str(i))
        
        return result
        
        
        
# @lc code=end

