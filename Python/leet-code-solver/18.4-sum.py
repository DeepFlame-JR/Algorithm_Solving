#
# @lc app=leetcode id=18 lang=python3
#
# [18] 4Sum
#

# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        result_set = set()
        nums.sort()        
        
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                l = j+1
                r = len(nums)-1
                while l < r:
                    left = nums[l]
                    right = nums[r]
                    total = nums[i]+nums[j]+left+right
                    if total == target and (nums[i], nums[j], left, right) not in result_set:
                        result.append([nums[i], nums[j], left, right])
                        result_set.add((nums[i], nums[j], left, right))
                    if total < target:
                        l += 1
                    else:
                        r -= 1 
        return result
            
        
# @lc code=end

