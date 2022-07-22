package LinkedList

// https://leetcode.com/problems/partition-list/

object leet86 extends App{
   // Definition for singly-linked list.
   class ListNode(_x: Int = 0, _next: ListNode = null) {
     var next: ListNode = _next
     var x: Int = _x
   }

  object Solution {
    def partition(head: ListNode, x: Int): ListNode = {
      val (dummy1, dummy2) = (new ListNode(), new ListNode())
      var (cur1, cur2) = (dummy1, dummy2)

      var cur = head
      while (cur != null){
        if(cur.x < x) {
          cur1.next = cur
          cur1 = cur
        }
        else{
          cur2.next = cur
          cur2 = cur
        }

        cur = cur.next
      }

      cur1.next=dummy2.next
      cur2.next=null
      dummy1.next
    }
  }

}
