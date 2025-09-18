#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#

# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def sort(left, right):
            if left < right:
                mid = (left+right) // 2
                sort(left, mid)
                sort(mid+1, right)
                merge(left, mid, right)
        
        def merge(left, mid, right):
            sorted = []
            l, r = left, mid+1
            while l <= mid and r <= right:
                if nums[l] <= nums[r]:
                    sorted.append(nums[l])
                    l += 1
                else:
                    sorted.append(nums[r])
                    r += 1
            while l <= mid:
                sorted.append(nums[l])
                l += 1
            while r <= right:
                sorted.append(nums[r])
                r += 1
            
            for i in range(left, right+1):
                nums[i] = sorted[i-left]
        
        sort(0, len(nums)-1)
        return nums
        

        
# @lc code=end

