#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> Optional[ListNode]:
        dummy = ListNode(-1)
        cur = dummy
        
        while list1 is not None and list2 is not None:
            l = ListNode()
            if list1.val > list2.val:
                l.val = list2.val
                list2 = list2.next
            else:
                l.val = list1.val
                list1 = list1.next
            cur.next = l
            cur = cur.next
        return dummy.next
                
            
        
# @lc code=end

