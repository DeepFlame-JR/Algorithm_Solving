#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        def dfs(i, path):
            if i == len(nums):
                result.append(path)
                return
            
            dfs(i+1, path + [nums[i]])
            dfs(i+1, path)
        
        dfs(0, [])
        return result
        
        
# @lc code=end

