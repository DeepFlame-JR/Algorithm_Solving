package Tree

object leet101 extends App{
  // Definition for a binary tree node.
  class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
    var value: Int = _value
    var left: TreeNode = _left
    var right: TreeNode = _right
  }

  object Solution {
    def isSymmetric(root: TreeNode): Boolean = {
      isSymmetric_recur(root.left, root.right)
    }

    def isSymmetric_recur(l:TreeNode, r:TreeNode):Boolean = {
      if(l==null||r==null)
        return l==null&&r==null

      if(l.value != r.value)
        return false

      isSymmetric_recur(l.left, r.right) && isSymmetric_recur(l.right, r.left)
    }
  }

  println(Solution.isSymmetric(new TreeNode(3)))
}
