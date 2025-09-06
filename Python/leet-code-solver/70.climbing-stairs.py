#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        arr = [0, 1, 2, 3]
        for i in range(4, n+1):
            arr.append(arr[i-2]+arr[i-1])
        return arr[n]
        
# @lc code=end

