package Tree

// https://leetcode.com/problems/path-sum-ii/

object leet113 extends App {

  // Definition for a binary tree node.
  class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
   var value: Int = _value
   var left: TreeNode = _left
   var right: TreeNode = _right
  }

  object Solution {
    def pathSum(root: TreeNode, targetSum: Int): List[List[Int]] = {
      var ans = List.empty[List[Int]]

      def helper(cur:TreeNode, cumList: List[Int]):Unit = {
        if(cur == null) return

        val tempList = cumList :+ cur.value
        if(cur.left == null && cur.right == null){
          if(tempList.sum == targetSum){
            ans :+= tempList
            return
          }
        }
        helper(cur.left, tempList)
        helper(cur.right, tempList)
      }

      helper(root, List())
      ans
    }
  }
}
