package Tree

import javax.swing.tree.TreeNode

// https://leetcode.com/problems/maximum-depth-of-binary-tree/

object leet104 {

   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def maxDepth(root: TreeNode): Int = {
      if(root == null)
        return 0

      var ans = 0
      def maxDepthRecursive(cur: TreeNode, depth: Int): Unit = {
        if(cur.left == null && cur.right == null){
          ans = math.max(depth, ans)
        }

        if(cur.left != null)
          maxDepthRecursive(cur.left, depth+1)

        if(cur.right != null)
          maxDepthRecursive(cur.right, depth+1)
      }

      maxDepthRecursive(root,1)
      ans
    }
  }

  Solution.maxDepth(new TreeNode())
}
