#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        to_target_dict = {}
        for i, n in enumerate(nums):
            if n in to_target_dict:
                return [to_target_dict[n], i]
            to_target_dict[target - n] = i
        
# @lc code=end

