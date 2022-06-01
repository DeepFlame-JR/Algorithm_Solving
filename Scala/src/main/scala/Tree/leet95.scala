package Tree

// https://leetcode.com/problems/unique-binary-search-trees-ii/

object leet95 extends App {
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def generateTrees(n: Int): List[TreeNode] = {
      generateTrees_recur(1, n)
    }

    def generateTrees_recur(m:Int, n:Int): List[TreeNode] = {
      var result = List.empty[TreeNode]
      if(m > n){
        result :+= null
      }

      for(i <- m to n){
        val left_trees = generateTrees_recur(m, i-1)
        val right_trees = generateTrees_recur(i+1, n)

        for(l <- left_trees ; r <- right_trees){
          result :+= new TreeNode(i, l, r)
        }
      }
      result
    }
  }

  println(Solution.generateTrees(3))

}
