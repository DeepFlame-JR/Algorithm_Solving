package LinkedList

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

object leet19 extends App{
  // Definition for singly-linked list.
  class ListNode(_x: Int = 0, _next: ListNode = null) {
    var next: ListNode = _next
    var x: Int = _x
  }

  object Solution {
    def removeNthFromEnd(head: ListNode, n: Int): ListNode = {
      var endFinder = head

      for(i <- 0 until n){
        endFinder = endFinder.next
      }

      if(endFinder == null)
        return head.next

      var prev:ListNode = null
      var cur:ListNode = head
      while(endFinder != null){
        prev = cur
        cur = cur.next
        endFinder = endFinder.next
      }

      prev.next = cur.next

      head
    }
  }
}
