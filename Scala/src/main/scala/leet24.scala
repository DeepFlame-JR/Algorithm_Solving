import javax.management.ListenerNotFoundException

object leet24 extends App{

  //Definition for singly-linked list.
  class ListNode(_x: Int = 0, _next: ListNode = null) {
    var next: ListNode = _next
    var x: Int = _x
  }

  object Solution {
    def swapPairs(head: ListNode): ListNode = {
      val dummy:ListNode = new ListNode()
      dummy.next = head

      var cur:ListNode = dummy
      while(cur.next != null && cur.next.next != null){
        // swap next(next1) and next.next(next2)
        val next1 = cur.next
        val next2 = cur.next.next
        next1.next = next2.next
        next2.next = next1
        cur.next = next2
        cur = next1
      }
      dummy.next
    }
  }

}
