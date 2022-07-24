package Tree

object leet116 extends App {
   // Definition for a Node.
   class Node(var _value: Int) {
     var value: Int = _value
     var left: Node = null
     var right: Node = null
     var next: Node = null
   }

  object Solution {
    def connect(root: Node): Node = {
      var level_node = Array.empty[Node]
      var level_count = Array.empty[Int]


      def helper(cur: Node, level: Int): Unit = {
        if(cur == null)
          return

        if(level_node.length < level+1){ // level 중 처음임
          level_node :+= cur
          level_count :+= 1
        }
        else{
          if(math.pow(2, level) == level_count(level)) {
            cur.next = null
          }
          else{
            level_node(level).next = cur
            level_node(level) = cur
            level_count(level) += 1
          }
        }

        helper(cur.left, level+1)
        helper(cur.right, level+1)
      }

      root.next = null
      helper(root, 0)
      root
    }
  }
}
