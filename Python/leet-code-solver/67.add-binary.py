#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
#

# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        sm_10 = int(a) + int(b)
        sm_str = str(sm_10)
        
        carry = 0
        for n in sm_str[::-1]:
            num = int(n)
            num += carry
            res += str(num%2)
            carry = num//2
            
        if carry == 1:
            res += "1"
        return res[::-1]
            
        
# @lc code=end

