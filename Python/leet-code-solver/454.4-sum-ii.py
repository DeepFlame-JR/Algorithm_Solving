#
# @lc app=leetcode id=454 lang=python3
#
# [454] 4Sum II
#

# @lc code=start
class Solution:
    
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        sm = defaultdict(int)
        
        for n1 in nums1:
            for n2 in nums2:
                sm[n1+n2] += 1
        
        result = 0
        for n3 in nums3:
            for n4 in nums4:
                result += sm[-(n3+n4)]
        return result
            
        
        
# @lc code=end

