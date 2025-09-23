#
# @lc app=leetcode id=131 lang=python3
#
# [131] Palindrome Partitioning
#

# @lc code=start
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        s_list = list(s)
        
        def dfs(i, sub, part):
            if i == len(s_list):
                if sub == "":
                    result.append(part)
                return

            ch = s_list[i]
            dfs(i+1, "", part + [ch])
            
            if sub and sub[0] == ch:
                dfs(i+1, "", part + [sub+ch])
            else:
                dfs(i+1, sub+ch, part)
        
        dfs(0, "", [])
        return result
    
        
# @lc code=end

