package Tree

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

object leet236 extends App{
  // Definition for a binary tree node.
  class TreeNode(var _value: Int) {
    var value: Int = _value
    var left: TreeNode = null
    var right: TreeNode = null
  }

  object Solution {
    def lowestCommonAncestor(root: TreeNode, p: TreeNode, q: TreeNode): TreeNode = {
      // 현재 노드가 leaf 노드이거나
      // p 또는 q 노드이다. (그 아래에 p 또는 q 노드가 있으면 해당 노드가 LCA임으로 return)
      if(root == null || root.value==p.value || root.value==q.value)
        return root

      val left = lowestCommonAncestor(root.left, p, q)
      val right = lowestCommonAncestor(root.right, p, q)

      // 왼쪽 오른쪽이 모두 null이 아닌 공통 조상을 찾고 있을 경우 현재 노드가 LCA이다.
      if(left != null && right != null)
        return root

      if(left == null) right else left
    }

    /*
    def lowestCommonAncestor(root: TreeNode, p: TreeNode, q: TreeNode): TreeNode = {
      var ans:TreeNode = null

      def helper(cur: TreeNode): Boolean = {
        if(cur == null || ans != null)
          return false

        val left = helper(cur.left)
        val right = helper(cur.right)

        if(ans == null){
          if((left && right)
            ||((left || right) && (cur.value==p.value || cur.value==q.value))
          ){
            ans = cur
          }
        }

        left || right || cur.value==p.value || cur.value==q.value
      }
      helper(root)

      ans
    }
    */
  }


}
