package Tree

// https://leetcode.com/problems/unique-binary-search-trees/

object leet96 extends App {
  object Solution {
    def numTrees(N: Int): Int = {
      var f = List[Int](1,1,2)
      for(n <- 3 to N){
        var temp = 0
        for (k <- 0 until n){
          temp += f(n-1-k)*f(k)
        }
        f = f :+ temp
      }
      f(N)
    }
  }

  println(Solution.numTrees(1))
  println(Solution.numTrees(2))
  println(Solution.numTrees(3))
  println(Solution.numTrees(4))
}
