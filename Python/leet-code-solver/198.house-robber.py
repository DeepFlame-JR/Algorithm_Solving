#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        prev_1, prev_2 = 0, 0

        for num in nums:
            # [2,1,1,2]
            # 두번째 항목을 훔치게 되면 이 전 것을 못 훔치고, 그 다음 것도 못 훔치는데,
            # 이 전 것이 더 크다면 굳이 두번째를 훔치지 않아도 된다.
            sm = max(num+prev_2, prev_1)
            prev_2 = prev_1
            prev_1 = sm
        return max(prev_1, prev_2)
        
        
        
        
# @lc code=end

