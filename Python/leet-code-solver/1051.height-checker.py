#
# @lc app=leetcode id=1051 lang=python3
#
# [1051] Height Checker
#

# @lc code=start
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = sorted(heights)
        result = 0
        for i in range(len(heights)):
            if heights[i] != expected[i]:
                result += 1
        return result
            
                
        
# @lc code=end

