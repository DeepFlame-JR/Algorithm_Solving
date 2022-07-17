package Tree

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

object leet114 extends App{

  // Definition for a binary tree node.
  class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
    var value: Int = _value
    var left: TreeNode = _left
    var right: TreeNode = _right
  }

  object Solution {
    def flatten(root: TreeNode): Unit = {
      var cur = root
      while(cur != null){
        if(cur.left != null){
          var rightest = cur.left
          while(rightest.right != null) {
            rightest = rightest.right
          }
          rightest.right = cur.right
          cur.right = cur.left
          cur.left = null
        }
        cur = cur.right
      }
    }
  }

  val tree = new TreeNode(1)
  tree.left = new TreeNode(2)

  Solution.flatten(tree)
  println(tree.value, tree.right.value)
}
