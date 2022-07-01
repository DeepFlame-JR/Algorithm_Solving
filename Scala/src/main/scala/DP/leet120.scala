package DP



object leet120 extends App {
  object Solution {
    def minimumTotal(triangle: List[List[Int]]): Int = {
      if(triangle.length == 1) return triangle.head.head

      val dp = triangle.last.toArray
      for(i <- triangle.length - 2 to 0 by -1){
        for(j <- 0 until triangle(i).length){
          dp(j) = math.min(dp(j), dp(j+1)) + triangle(i)(j)
        }
      }

      dp.head
    }
  }

  println(Solution.minimumTotal(List(List(2), List(3,4), List(6,5,7), List(4,1,8,3))))
  println(Solution.minimumTotal(List(List(1), List(5,2), List(10,100,100))))
}
