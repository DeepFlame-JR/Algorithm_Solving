#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        cur = dummy
        add_1 = 0
        
        while l1 is not None or l2 is not None:
            l1_value = l1.val if l1 is not None else 0
            l2_value = l2.val if l2 is not None else 0
            sm = l1_value + l2_value + add_1
            add_1 = sm//10
            l = ListNode(sm%10)
            cur.next = l
            cur = cur.next
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next
        
        if add_1 == 1:
            cur.next = ListNode(1)
        
        return dummy.next


            
# @lc code=end

