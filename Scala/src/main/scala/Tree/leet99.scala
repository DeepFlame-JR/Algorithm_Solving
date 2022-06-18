package Tree

import javax.swing.tree.TreeNode

// https://leetcode.com/problems/recover-binary-search-tree/
// Inorder Traversal로 정렬했을 때, 값들이 오름차순으로 정렬되어야 한다.

object leet99 extends App {

  // Definition for a binary tree node.
  class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
   var value: Int = _value
   var left: TreeNode = _left
   var right: TreeNode = _right
  }

  object Solution {
    var firstNode:TreeNode = null
    var secondNode:TreeNode = null
    var prevNode:TreeNode = new TreeNode(Int.MinValue)

    def recoverTree(root: TreeNode): Unit = {
      recoverTreeHelper(root)

      val temp = firstNode.value
      firstNode.value = secondNode.value
      secondNode.value = temp
    }

    def recoverTreeHelper(cur:TreeNode): Unit = {
      if(cur == null)
        return

      recoverTreeHelper(cur.left)

      if(prevNode.value >= cur.value){
        if(firstNode == null)
          firstNode = prevNode // 비교적 큰 값을 저장

        if(firstNode != null)
          secondNode = cur // 비교적 작은 값을 저장
      }
      prevNode = cur

      recoverTreeHelper(cur.right)
    }
  }

  val tree = new TreeNode(3)
  tree.left = new TreeNode(1) ; tree.right = new TreeNode(4)
  tree.right.left = new TreeNode(2)
  Solution.recoverTree(tree)
}
