package Tree

// https://leetcode.com/problems/add-one-row-to-tree/

object leet623 extends App{
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def addOneRow(root: TreeNode, `val`: Int, depth: Int): TreeNode = {
      if(depth == 1)
        return new TreeNode(`val`, root)

      def helper(cur:TreeNode, level:Int): Unit = {
        if(cur == null || level >= depth)
          return

        if(level < depth-1){
          helper(cur.left, level+1)
          helper(cur.right, level+1)
        }
        else if(level == depth-1){
          cur.left = new TreeNode(`val`, cur.left)
          cur.right = new TreeNode(`val`, null, cur.right)
        }
      }

      helper(root, 1)
      root
    }
  }
}
