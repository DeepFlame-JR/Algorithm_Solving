package Tree

object leet199 {

   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def rightSideView(root: TreeNode): List[Int] = {
      var ans = Array.empty[Int]

      def helper(cur: TreeNode, level: Int): Unit = {
        if(cur == null) return

        if(ans.length < level+1){
          ans :+= cur.value
        }
        else{
          ans(level) = cur.value
        }

        helper(cur.left, level+1)
        helper(cur.right, level+1)
      }

      helper(root, 0)
      ans.toList
    }
  }
}
