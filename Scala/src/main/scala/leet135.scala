// https://leetcode.com/problems/candy/

object leet135 extends App {
  object Solution {
    def candy(ratings: Array[Int]): Int = {
      val N = ratings.length
      var candy_arr = Array.fill(N){1}

      def calculate(ratings:Array[Int]): Unit = {
        var stack = 1
        for(i <- 1 until N){
          if(ratings(i) > ratings(i-1)){
            stack += 1
            candy_arr(i) = math.max(candy_arr(i), stack)
          }
          else{
            stack = 1
          }
        }
      }

      // 주변(neighbors)보다 사탕을 많이 받아야한다
      // 그 상황에서 좌우를 보는 것이 아니라 양쪽에서 사탕 stack이 얼마나 쌓였는지를 체크하는 것이 중요
      // left > right
      calculate(ratings)

      // right > left
      candy_arr = candy_arr.reverse
      calculate(ratings.reverse)

      candy_arr.sum
    }
  }
  println(Solution.candy(Array(1,0,2))) // 4
  println(Solution.candy(Array(1,2,2))) // 5
  println(Solution.candy(Array(1,2,87,87,87,2,1))) // 13
  println(Solution.candy(Array(1,3,2,2,1))) // 7
}
