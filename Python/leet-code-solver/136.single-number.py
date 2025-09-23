#
# @lc app=leetcode id=136 lang=python3
#
# [136] Single Number
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        single_list = set()
        over_2_list = set()
        
        for num in nums:
            if num in single_list:
                single_list.discard(num)
                over_2_list.add(num)
            elif num in over_2_list:
                continue
            else:
                single_list.add(num)
        return single_list[0]
        
# @lc code=end

