package Tree

import javax.swing.tree.TreeNode

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

object leet103 extends App {
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def zigzagLevelOrder(root: TreeNode): List[List[Int]] = {
      var ans = Array.empty[List[Int]]

      def zigzagHelper(cur:TreeNode, level:Int):Unit ={
        if(cur==null)
          return

        if(level < ans.length){
          if(level%2 == 1) // 반대로 List를 구성한다
            ans(level) +:= cur.value
          else
            ans(level) :+= cur.value
        }
        else{
          ans :+= List(cur.value)
        }

        zigzagHelper(cur.left,level+1)
        zigzagHelper(cur.right,level+1)
      }

      zigzagHelper(root, 0)
      ans.toList
    }
  }

  val test = new TreeNode(3)
  test.left = new TreeNode(9); test.right = new TreeNode(20)
  test.right.left = new TreeNode(15) ; test.right.right = new TreeNode(7)

  Solution.zigzagLevelOrder(test)
}


