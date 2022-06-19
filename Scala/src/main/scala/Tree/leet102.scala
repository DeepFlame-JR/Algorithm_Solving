package Tree

// https://leetcode.com/problems/binary-tree-level-order-traversal/

object leet102 extends App {
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def levelOrder(root: TreeNode): List[List[Int]] = {
      var ans = Array[List[Int]]()

      DFSHelper(root, 0)

      def DFSHelper(cur:TreeNode, level:Int): Unit={
        if(cur == null)
          return

        if(ans.length > level){
          ans(level) :+= cur.value
        }
        else{
          ans :+= List[Int](cur.value)
        }
        DFSHelper(cur.left, level+1)
        DFSHelper(cur.right, level+1)
      }
      ans.toList
    }
  }
}
