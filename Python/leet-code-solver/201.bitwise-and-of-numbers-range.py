#
# @lc app=leetcode id=201 lang=python3
#
# [201] Bitwise AND of Numbers Range
#

# @lc code=start
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        ans = 0
        bits = 1 << 31

        for i in range(32):
            if left & bits and right & bits:
                if right-left < bits:
                    ans += bits
            bits >>= 1
        return ans
# @lc code=end

