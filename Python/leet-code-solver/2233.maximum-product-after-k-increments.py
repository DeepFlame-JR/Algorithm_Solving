#
# @lc app=leetcode id=2233 lang=python3
#
# [2233] Maximum Product After K Increments
#

# @lc code=start
class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        import heapq

        heap = []
        for n in nums:
            heapq.heappush(heap,n)
        
        for _ in range(k):
            smallest = heapq.heappop(heap)
            heapq.heappush(heap, smallest+1)
            
        result = 1
        for n in nums:
            result *= n
        return result
        
# @lc code=end

