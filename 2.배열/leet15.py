# Given an integer array nums, return all the triplets [nums[i], nums[j], nums[
# k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
#
#  Notice that the solution set must not contain duplicate triplets.
#
#
#  Example 1:
#  Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
#  Example 2:
#  Input: nums = []
# Output: []
#  Example 3:
#  Input: nums = [0]
# Output: []
#
#
#  Constraints:
#
#
#  0 <= nums.length <= 3000
#  -10⁵ <= nums[i] <= 10⁵
#
#  Related Topics Array Two Pointers Sorting 👍 15223 👎 1466


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3: return []

        nums.sort()
        ans = []
        for i in range(len(nums)-2):
            left, right = i+1, len(nums)-1

            if i > 0 and nums[i-1] == nums[i]:
                continue

            while left < right:
                sum3 = nums[i] + nums[left] + nums[right]
                if sum3 == 0:
                    ans.append([nums[i],nums[left],nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif sum3 > 0:
                    right -= 1
                else:
                    left += 1
        return ans
# leetcode submit region end(Prohibit modification and deletion)
