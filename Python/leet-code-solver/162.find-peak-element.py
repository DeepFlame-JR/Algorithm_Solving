#
# @lc app=leetcode id=162 lang=python3
#
# [162] Find Peak Element
#

# @lc code=start
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l = 0 
        r = len(nums)-1
        while l < r:
            if nums[l] < nums[r]:
                l += 1
            else:
                r -= 1
        return l 
        
# @lc code=end

