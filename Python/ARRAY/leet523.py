# https://leetcode.com/problems/continuous-subarray-sum/

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        cum_dict = {0: -1}  # 누적합이 0일 때, 조건 만족

        cum = 0
        for i in range(len(nums)):
            cum = (cum + nums[i]) % k

            if cum in cum_dict.keys():  # 앞에 누적합이 같은 곳이 있으면 그 전 값을 빼면 조건 만족
                if i - cum_dict[cum] > 1:  # at least 2
                    return True
            else:
                cum_dict[cum] = i

        return False


