package Tree

// https://leetcode.com/problems/path-sum/submissions/

object leet112 extends App {
  // Definition for a binary tree node.
  class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
    var value: Int = _value
    var left: TreeNode = _left
    var right: TreeNode = _right
  }

  object Solution {
    def hasPathSum(root: TreeNode, targetSum: Int): Boolean = {
      var ans = false
      def helper(cur:TreeNode, Sum:Int):Unit = {
        if(ans || cur == null) return

        if(cur.left == null && cur.right == null){
          if(Sum+cur.value == targetSum){
            ans = true
            return
          }
        }
        helper(cur.left, Sum+cur.value)
        helper(cur.right, Sum+cur.value)
      }

      helper(root, 0)
      ans
    }
  }
}
