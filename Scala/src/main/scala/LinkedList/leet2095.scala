package LinkedList

object leet2095 extends App {

  class ListNode(var _x: Int = 0) {
    var next: ListNode = null
    var x: Int = _x
  }

  object Solution {
    def deleteMiddle(head: ListNode): ListNode = {
      if(head.next == null)
        return null

      var prev:ListNode = null
      var cur:ListNode = head
      var endFinder:ListNode = head.next

      while(endFinder != null){
        prev = cur
        cur = cur.next

        for(_ <- 0 until 2){
          if(endFinder != null){
            endFinder = endFinder.next
          }
        }
      }

      prev.next = cur.next
      head
    }
  }
}
