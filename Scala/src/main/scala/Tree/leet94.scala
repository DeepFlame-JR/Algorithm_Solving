package Tree

// https://leetcode.com/problems/binary-tree-inorder-traversal/
// Inorder Traversal
// Left -> node -> right

object leet94 extends App {
  // Definition for a binary tree node.
  class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
    var value: Int = _value
    var left: TreeNode = _left
    var right: TreeNode = _right
  }

  object Solution {
    def inorderTraversal(root: TreeNode): List[Int] = {
      if (root == null) return List()
      inorderTraversal(root.left) ::: List(root.value) ::: inorderTraversal(root.right)
    }
  }
}
