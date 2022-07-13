package DP

object leet509 extends App {
  object Solution {
    def fib(n: Int): Int = {
      var dp = Array(0,1,1)

      for(i <- 3 to n){
        dp :+= dp(i-1)+dp(i-2)
      }

      dp(n)
    }
  }
  println(Solution.fib(2))
  println(Solution.fib(3))
  println(Solution.fib(4))
  println(Solution.fib(5))
}
