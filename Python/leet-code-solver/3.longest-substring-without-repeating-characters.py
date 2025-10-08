#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = 0
        q = []
        
        for ch in s:
            if ch in q:
                while q:
                    if q[0] == ch:
                        q.pop(0)
                        break
                    else:
                        q.pop(0)
            q.append(ch)
            result = max(result, len(q))
        return result
                
        
# @lc code=end

