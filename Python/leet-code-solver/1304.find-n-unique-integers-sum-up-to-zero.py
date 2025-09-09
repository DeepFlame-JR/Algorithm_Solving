#
# @lc app=leetcode id=1304 lang=python3
#
# [1304] Find N Unique Integers Sum up to Zero
#

# @lc code=start
class Solution:
    def sumZero(self, n: int) -> List[int]:
        a = n//2
        result = list(range(-a, a+1))
        if n % 2 == 0:
            result.remove(0)
        return result
        
        
# @lc code=end

