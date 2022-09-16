package Tree

object leet1457 extends App{
   // Definition for a binary tree node.
   class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
     var value: Int = _value
     var left: TreeNode = _left
     var right: TreeNode = _right
   }

  object Solution {
    def pseudoPalindromicPaths (root: TreeNode): Int = {
      var ans = 0

      def helper (cur: TreeNode, arr_cnt:Array[Int]): Unit = {
        arr_cnt(cur.value) += 1

        if(cur.left == null && cur.right == null){
          // Check palindorome
          if(arr_cnt.count(_%2==1) == arr_cnt.sum%2)
            ans += 1
        }
        else{
          if(cur.left != null)
            helper(cur.left, arr_cnt)

          if(cur.right != null)
            helper(cur.right, arr_cnt)
        }

        arr_cnt(cur.value) -= 1
      }

      helper(root, Array.fill(10){0})

      ans
    }
  }

}
