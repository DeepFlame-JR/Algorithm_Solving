#
# @lc app=leetcode id=1780 lang=python3
#
# [1780] Check if Number is a Sum of Powers of Three
#

# @lc code=start
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n > 0:
            if n-1 % 3 == 0:
                n = (n-1) // 3
            elif n % 3 == 0:
                n //= 3
            else:
                return False
        return True
        
# @lc code=end

