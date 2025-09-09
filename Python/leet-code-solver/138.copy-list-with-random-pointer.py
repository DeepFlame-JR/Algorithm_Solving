#
# @lc app=leetcode id=138 lang=python3
#
# [138] Copy List with Random Pointer
#

# @lc code=start
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        new_node_hash = {}
        new_node_hash[None] = None
        
        cur = head
        while cur:
            new_node_hash[cur] = Node(cur.val)
            cur = cur.next
        
        cur = head
        while cur:
            new_node_hash[cur].next = new_node_hash[cur.next]
            new_node_hash[cur].random = new_node_hash[cur.random]
            cur = cur.next
            
        return new_node_hash[head]
    
        
# @lc code=end

