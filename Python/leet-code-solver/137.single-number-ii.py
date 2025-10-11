#
# @lc app=leetcode id=137 lang=python3
#
# [137] Single Number II
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        first = 0
        second = 0 
        
        for n in nums:
            # 첫 번째 나왔다면 입력됨
            # 두 번째 나왔다면 first에 두번 입력되서 first에서 지워짐, second에 입력됨
            # 세 번째 나왔다면 무시됨
            first ^= (n & ~second)  
            second ^= (n & ~first)
        
        return first
        
# @lc code=end

