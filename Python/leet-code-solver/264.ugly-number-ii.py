#
# @lc app=leetcode id=264 lang=python3
#
# [264] Ugly Number II
#

# @lc code=start
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        l = set([2,3,5])
        
        result = 1
        for n in range(1, n):
            result = min(l)
            l.remove(result)
            l = l.union(set([result*2,result*3,result*5]))
        return result
        
# @lc code=end

