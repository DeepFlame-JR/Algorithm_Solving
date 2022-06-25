package Tree

object leet105 extends App {
   // Definition for a binary tree node.
    class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
      var value: Int = _value
      var left: TreeNode = _left
      var right: TreeNode = _right
    }

  object Solution {
    def buildTree(preorder: Array[Int], inorder: Array[Int]): TreeNode = {
      var p = 0;

      def buildTreeHelper(inorder: Array[Int]): TreeNode = {
        if(inorder.length == 0) return null

        val cur = new TreeNode(preorder(p))
        val index = inorder.indexOf(preorder(p))
        p+=1

        // root를 어떻게 찾을지 고민해보자
        // preorder        inorder
        //    1               2
        //  2   3           1   3
        // preorder에서 처음 나오는 수가 inorder의 root이고, 앞의 수는 left 뒤의 수는 right이다.
        cur.left = buildTreeHelper(inorder.take(index))
        cur.right = buildTreeHelper(inorder.drop(index+1))
        cur
      }

      buildTreeHelper(inorder)
    }
  }

  Solution.buildTree(Array(3,9,20,15,7), Array(9,3,15,20,7))
}
