package LinkedList

// https://leetcode.com/problems/delete-node-in-a-linked-list/

object leet237 extends App{
  // Definition for singly-linked list.
  class ListNode(var _x: Int = 0) {
    var next: ListNode = null
    var x: Int = _x
  }

  object Solution {
    def deleteNode(node: ListNode): Unit = {
      node.x = node.next.x
      node.next = node.next.next
    }
  }
}
