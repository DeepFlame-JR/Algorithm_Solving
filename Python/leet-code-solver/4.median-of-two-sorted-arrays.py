#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged = nums1 + nums2
        
        merged.sort()
        mid = len(merged)//2
        if len(merged) % 2 == 1:
            return merged[mid]
        else:
            return (merged[mid]+merged[mid-1])/2
        
# @lc code=end

