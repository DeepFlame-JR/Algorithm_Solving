# Given n pairs of parentheses, write a function to generate all combinations
# of well-formed parentheses.
#
#
#  Example 1:
#  Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]
#  Example 2:
#  Input: n = 1
# Output: ["()"]
#
#
#  Constraints:
#
#
#  1 <= n <= 8
#
#  Related Topics String Dynamic Programming Backtracking 👍 12555 👎 486


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def DFS(open, close, s):
            if open == n:
                s += ')'*(open-close)
                ans.append(s)
                return

            DFS(open+1, close, s + '(')
            if open-close > 0:
                DFS(open, close+1, s+')')

        DFS(1, 0, '(')
        return ans
# leetcode submit region end(Prohibit modification and deletion)
