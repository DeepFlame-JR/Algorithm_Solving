package LinkedList

// https://leetcode.com/problems/palindrome-linked-list/

object leet234 extends App{
   // Definition for singly-linked list.
   class ListNode(_x: Int = 0, _next: ListNode = null) {
     var next: ListNode = _next
     var x: Int = _x
   }

  object Solution {
    def isPalindrome(head: ListNode): Boolean = {
      var seq = Array.empty[Int]

      var cur = head
      while (cur != null) {
        seq :+= cur.x
        cur = cur.next
      }

      seq.sameElements(seq.reverse)
    }
  }

  import scala.collection.mutable._
  object Solution2 {
    def isPalindrome(head: ListNode): Boolean = {
      val queue = Queue.empty[Int]
      val stack = Stack.empty[Int]

      var cur = head
      while(cur != null){
        queue.enqueue(cur.x)
        stack.push(cur.x)
        cur = cur.next
      }

      while(queue.nonEmpty){
        if(queue.dequeue() != stack.pop())
          return false
      }
      true
    }
  }

  val head = new ListNode(1, new ListNode(2))
  println(Solution.isPalindrome(head))
}
