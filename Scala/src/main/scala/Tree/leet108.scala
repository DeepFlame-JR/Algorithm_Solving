package Tree

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

object leet108 extends App {
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def sortedArrayToBST(nums: Array[Int]): TreeNode = {
      if(nums.length == 0)
        return null

      val mid = (nums.length-1)/2
      println(nums.mkString(","), mid)
      val tree = new TreeNode(nums(mid))

      tree.left = sortedArrayToBST(nums.take(mid))
      tree.right = sortedArrayToBST(nums.drop(mid+1))
      tree
    }
  }

  Solution.sortedArrayToBST(Array(-10,-3,0,5,9))
}
