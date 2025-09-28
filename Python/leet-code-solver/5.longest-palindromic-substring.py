#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def longestPalindromeFromCenter(l, r):
            while l >= 0 and r <= len(s)-1 and s[l] == s[r]: # 양 쪽 두개만 비교한다
                l -= 1
                r += 1
            return s[l+1:r] # 갈라지기 전 값을 가져오기 위해서 
        
        max_s = s[0]
        
        for i in range(len(s)-1):
            odd_long_s = longestPalindromeFromCenter(i, i)
            even_long_s = longestPalindromeFromCenter(i, i+1)
            
            if len(odd_long_s) > len(max_s):
                max_s = odd_long_s
            if len(even_long_s) > len(max_s):
                max_s = even_long_s
        
        return max_s
        
# @lc code=end

