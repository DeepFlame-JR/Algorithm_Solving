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
 
