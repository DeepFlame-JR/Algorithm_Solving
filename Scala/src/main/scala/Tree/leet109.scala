package Tree

// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

object leet109 extends App {
   //Definition for singly-linked list.
   class ListNode(_x: Int = 0, _next: ListNode = null) {
     var next: ListNode = _next
     var x: Int = _x
   }

   //Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def sortedListToBST(head: ListNode): TreeNode = {
      if(head==null)
        return null

      var sortedList = Array.empty[Int]
      var cur = head
      while(cur != null){
        sortedList :+= cur.x
        cur = cur.next
      }

      def helper(list: Array[Int]): TreeNode = {
        if(list.length == 0)
          return null

        val tree = new TreeNode()
        val mid = list.length / 2
        tree.value = list(mid)
        tree.left = helper(list.take(mid))
        tree.right = helper(list.drop(mid+1))
        tree
      }

      helper(sortedList)
    }
  }
}
