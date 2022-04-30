# Given a string s, return the longest palindromic substring in s.
#
#
#  Example 1:
#
#
# Input: s = "babad"
# Output: "bab"
# Explanation: "aba" is also a valid answer.
#
#
#  Example 2:
#
#
# Input: s = "cbbd"
# Output: "bb"
#
#
#
#  Constraints:
#
#
#  1 <= s.length <= 1000
#  s consist of only digits and English letters.
#
#  Related Topics String Dynamic Programming 👍 15216 👎 895


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 1: return s

        start, length = 0, 0
        for end in range(len(s)):
            # 기존 substring에서 자신만 추가하여 조건 성립 Ex. aaa
            if s[end-length:end+1] == s[end-length:end+1][::-1]:
                start, length = end-length, length+1
            # 기존 substring에서 자신과 앞을 추가하여 조건 성립 Ex. baaab
            elif end-length-1 >= 0 and s[end-length-1:end+1] == s[end-length-1:end+1][::-1]:
                start, length = end-length-1, length+2

        return s[start:start+length]
# leetcode submit region end(Prohibit modification and deletion)
