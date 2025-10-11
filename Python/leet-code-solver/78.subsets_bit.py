#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        N = len(nums)
        ans = []
    
        full = 1 << N
        for mask in range(full):
            tmp = []
            for i in range(N):
                if mask & (1<<i):
                    tmp.append(nums[i])
            ans.append(tmp)
        
        return ans
                    
            
        
        
# @lc code=end

