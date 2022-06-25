package Tree

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

object leet106 extends App {
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def buildTree(inorder: Array[Int], postorder: Array[Int]): TreeNode = {
      var p = 0
      val r_postorder = postorder.reverse

      def buildTreeHelper(r_inorder: Array[Int]): TreeNode = {
        if(p >= r_postorder.length || r_inorder.length == 0)
          return null

        val tree = new TreeNode(r_postorder(p))
        val ind = r_inorder.indexOf(tree.value)
        p += 1

        tree.right = buildTreeHelper(r_inorder.take(ind))
        tree.left = buildTreeHelper(r_inorder.drop(ind+1))
        tree
      }

      buildTreeHelper(inorder.reverse)
    }
  }

  Solution.buildTree(Array(9,3,15,20,7), Array(9,15,7,20,3))
}
