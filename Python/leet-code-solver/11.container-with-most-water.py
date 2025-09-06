#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height)-1
        m = 0
        while l < r:
            left = height[l]
            right = height[r]
            m = max(m, (r-l)*min(left, right))
            if left < right:
                l += 1
            else:
                r -= 1
        return m
        
# @lc code=end

