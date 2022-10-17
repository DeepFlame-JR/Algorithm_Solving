# You are given an integer n. We reorder the digits in any order (including the
# original order) such that the leading digit is not zero.
#
#  Return true if and only if we can do this so that the resulting number is a
# power of two.
#
#
#  Example 1:
#
#
# Input: n = 1
# Output: true
#
#
#  Example 2:
#
#
# Input: n = 10
# Output: false
#
#
#
#  Constraints:
#
#
#  1 <= n <= 10⁹
#
#
#  Related Topics Math Sorting Counting Enumeration 👍 1158 👎 282


# leetcode submit region begin(Prohibit modification and deletion)
import collections


class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        counter = collections.Counter(str(n))
        for i in range(31):
            if counter == collections.Counter(str(pow(2, i))):
                return True
        return False
# leetcode submit region end(Prohibit modification and deletion)
