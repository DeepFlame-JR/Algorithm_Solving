#
# @lc app=leetcode id=1935 lang=python3
#
# [1935] Maximum Number of Words You Can Type
#

# @lc code=start
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        result = 0
        for t in text.split():
            if list(t) == [c for c in t if c not in brokenLetters]:
                result += 1
        return result
        
        
# @lc code=end

