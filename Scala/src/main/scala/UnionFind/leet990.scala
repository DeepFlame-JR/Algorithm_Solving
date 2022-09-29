package UnionFind

// https://leetcode.com/problems/satisfiability-of-equality-equations/

object leet990 extends App{
  object Solution {
    def equationsPossible(equations: Array[String]): Boolean = {
      val root = Array.fill(26){0}
      root.indices.map(i => root(i)=i)

      def find(x:Int): Int = {
        if(root(x)==x) x
        else find(root(x))
      }

      def union(x:Int, y:Int): Unit = {
        root(find(y)) = find(x)
      }

      for(same <- equations.filter(_(1)=='=')){
        val a = same(0).toInt - 'a'
        val b = same(3).toInt - 'a'
        union(a, b)
      }

      for(diff <- equations.filter(_(1)=='!')){
        val a = diff(0).toInt - 'a'
        val b = diff(3).toInt - 'a'
        if(find(a) == find(b))
          return false
      }

      true
    }
  }
}
