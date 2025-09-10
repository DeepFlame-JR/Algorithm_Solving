#
# @lc app=leetcode id=2327 lang=python3
#
# [2327] Number of People Aware of a Secret
#

# @lc code=start
class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        delayers = {}
        remembers = {}
        
        delayers[delay+1] = 1
        delayer_cnt = 0
        remember_cnt = 0
        for day in range(1, n+1):
            if day in remembers:
                remember_cnt -= remembers[day]
                remembers[day] = 0
            
            if day in delayers:
                remember_cnt += delayers[day]
                delayer_cnt -= delayers[day]
                remembers[day + forget - delay] = delayers[day]
                
            delayers[day+delay] = remember_cnt
            delayer_cnt += remember_cnt

        return remember_cnt + delayer_cnt
            
        
        
        
# @lc code=end

