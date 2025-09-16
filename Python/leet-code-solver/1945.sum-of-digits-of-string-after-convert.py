#
# @lc app=leetcode id=1945 lang=python3
#
# [1945] Sum of Digits of String After Convert
#

# @lc code=start
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        s_str = ""
        for ch in s:
            s_str += str(ord(ch)-ord('a')+1)
        
        for _ in range(k):
            tmp = 0
            for ch in s_str:
                tmp += int(ch)
            s_str = str(tmp)
        return int(s_str)
                
            
        
# @lc code=end

