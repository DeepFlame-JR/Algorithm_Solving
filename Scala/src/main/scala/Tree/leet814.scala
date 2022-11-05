package Tree

object leet814 extends App {
  object Solution {
    // Definition for a binary tree node.
    class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
      var value: Int = _value
      var left: TreeNode = _left
      var right: TreeNode = _right
    }

    def pruneTree(root: TreeNode): TreeNode = {
      def helper(cur: TreeNode): TreeNode = {
        if (cur == null)
          return null

        cur.left = helper(cur.left)
        cur.right = helper(cur.right)

        if (cur.left == null && cur.right == null && cur.value == 0)
          null
        else
          cur
      }

      helper(root)
    }
  }
}
