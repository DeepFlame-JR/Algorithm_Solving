#
# @lc app=leetcode id=611 lang=python3
#
# [611] Valid Triangle Number
#

# @lc code=start
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        result = 0
        nums.sort()
        for k in range(2, len(nums)):
            i = 0
            j = k-1
            if nums[i] + nums[j] > nums[k]:
                result += j-i
                j -= 1
            else:
                i += 1
        return result
                
            
        
        
# @lc code=end

