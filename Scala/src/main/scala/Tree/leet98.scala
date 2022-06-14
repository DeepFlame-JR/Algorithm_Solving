package Tree

// https://leetcode.com/problems/validate-binary-search-tree/

object leet98 extends App{
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def isValidBST(root: TreeNode): Boolean = {
      isValidBSTRecursive(root.left, Long.MinValue, root.value) && isValidBSTRecursive(root.right, root.value, Long.MaxValue)
    }

    def isValidBSTRecursive(cur:TreeNode, minValue: Long, maxValue: Long): Boolean ={
      if(cur == null)
        return true

      if(cur.value >= maxValue || cur.value <= minValue)
        return false

      isValidBSTRecursive(cur.left, minValue, cur.value) && isValidBSTRecursive(cur.right, cur.value, maxValue)
    }
  }

  Solution.isValidBST(new TreeNode())
}
