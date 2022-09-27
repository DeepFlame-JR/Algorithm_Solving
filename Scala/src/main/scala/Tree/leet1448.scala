package Tree

object leet1448 extends App{
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
   var value: Int = _value
   var left: TreeNode = _left
   var right: TreeNode = _right
   }

  object Solution {
    def goodNodes(root: TreeNode): Int = {
      var ans = 0

      def helper(cur:TreeNode, local_max:Int):Unit = {
        if(cur == null) return
        if(cur.value >= local_max) ans += 1
        val new_max = math.max(local_max, cur.value)
        helper(cur.left, new_max)
        helper(cur.right, new_max)
      }

      helper(root, root.value)
      ans
    }
  }

}
