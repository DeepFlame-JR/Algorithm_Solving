package LinkedList

// https://leetcode.com/problems/reverse-linked-list-ii/

object leet92 extends App{
   // Definition for singly-linked list.
   class ListNode(_x: Int = 0, _next: ListNode = null) {
     var next: ListNode = _next
     var x: Int = _x
   }

  object Solution {
    def reverseBetween(head: ListNode, left: Int, right: Int): ListNode = {
      val mid = (left.toDouble+right.toDouble)/2

      val stack = scala.collection.mutable.Stack[ListNode]()
      var ind = 1
      var cur = head
      while(cur != null){
        if(left <= ind && ind <= right){
          if(ind<mid){
            stack.push(cur)
          }
          else if(ind > mid){
            val sym = stack.pop()
            val temp = sym.x
            sym.x = cur.x
            cur.x = temp
          }
        }
        cur = cur.next
        ind += 1
      }

      head
    }
  }

}
