# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']
# ', determine if the input string is valid.
#
#  An input string is valid if:
#
#
#  Open brackets must be closed by the same type of brackets.
#  Open brackets must be closed in the correct order.
#
#
#
#  Example 1:
#
#
# Input: s = "()"
# Output: true
#
#
#  Example 2:
#
#
# Input: s = "()[]{}"
# Output: true
#
#
#  Example 3:
#
#
# Input: s = "(]"
# Output: false
#
#
#
#  Constraints:
#
#
#  1 <= s.length <= 10⁴
#  s consists of parentheses only '()[]{}'.
#
#  Related Topics String Stack 👍 12648 👎 564


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def isValid(self, s: str) -> bool:
        open_close = dict()
        open_close['('] = ')'
        open_close['{'] = '}'
        open_close['['] = ']'

        Stack = []
        for w in s:
            if w in open_close.keys():
                Stack.append(w)
            else:
                if len(Stack) == 0: return False

                if open_close[Stack[-1]] == w:
                    Stack.pop()
                else:
                    return False
        return len(Stack) == 0
# leetcode submit region end(Prohibit modification and deletion)
