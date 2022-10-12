package Tree

// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

object leet429 extends App{
   // Definition for a Node.
   class Node(var _value: Int) {
   var value: Int = _value
   var children: List[Node] = List()
   }


  object Solution {
    def levelOrder(root: Node): List[List[Int]] = {
      var ans = Array.empty[List[Int]]

      def helper(cur:Node, level:Int):Unit={
        if(cur == null) return

        if(ans.length < level+1)
          ans :+= List.empty[Int]
        ans(level) :+= cur.value

        for(child <- cur.children)
          helper(child, level+1)
      }

      helper(root, 0)
      ans.toList
    }
  }

  Solution.levelOrder(new Node(1))
}
