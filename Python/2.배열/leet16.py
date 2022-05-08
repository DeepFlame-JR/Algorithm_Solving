# Given an integer array nums of length n and an integer target, find three
# integers in nums such that the sum is closest to target.
#
#  Return the sum of the three integers.
#
#  You may assume that each input would have exactly one solution.
#
#
#  Example 1:
#
#
# Input: nums = [-1,2,1,-4], target = 1
# Output: 2
# Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#
#
#  Example 2:
#
#
# Input: nums = [0,0,0], target = 1
# Output: 0
#
#
#
#  Constraints:
#
#
#  3 <= nums.length <= 1000
#  -1000 <= nums[i] <= 1000
#  -10⁴ <= target <= 10⁴
#
#  Related Topics Array Two Pointers Sorting 👍 5706 👎 245


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if len(nums) == 3:
            return sum(nums)
        nums.sort()

        ans = float('inf')
        for i in range(len(nums)-2):
            left, right = i+1, len(nums)-1
            if i > 0 and nums[i] == nums[i-1]:
                continue

            while left < right:
                sum3 = nums[i]+nums[left]+nums[right]
                if sum3 == target: return target
                if abs(sum3-target) < abs(ans-target):
                    ans = sum3

                if sum3-target > 0:
                    right -= 1
                else:
                    left += 1
        return ans
# leetcode submit region end(Prohibit modification and deletion)
