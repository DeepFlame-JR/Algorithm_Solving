#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        smallest_length = 200
        for s in strs:
            smallest_length = min(smallest_length, len(s))
        
        result = smallest_length
        while result > 0:
            criterior = strs[0][:result+1]
            accept = [s for s in strs if s.startswith(criterior)]
            if len(accept) == len(strs):
                return criterior
            result -= 1
        return ""
        
        
# @lc code=end

