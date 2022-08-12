package DP

// https://leetcode.com/problems/binary-trees-with-factors/

object leet823 extends App {
  object Solution {
    def numFactoredBinaryTrees(arr: Array[Int]): Int = {
      val MOD = math.pow(10, 9).toInt + 7
      val sorted_arr = arr.sortWith(_ < _)
      val dp = scala.collection.mutable.Map[Int, Long]() // 값이 너무 커지기 때문에 Long 타입 사용

      for (n <- sorted_arr) {
        dp += (n -> 1)
      }

      // 앞서 구한 factor의 tree 개수를 곱해서 사용한다.
      for (j <- 1 until sorted_arr.length) {
        val prod = sorted_arr(j)
        for (factor_index <- 0 until j) {
          val factor1 = sorted_arr(factor_index)
          val factor2 = prod / factor1
          if (prod % factor1 == 0 && dp.contains(factor2)) {
            dp(prod) += dp(factor1) * dp(factor2)
            dp(prod) %= MOD
          }
        }
      }

      (dp.values.sum % MOD).toInt
    }
  }

  println(Solution.numFactoredBinaryTrees(Array(2, 4))) // 3
  println(Solution.numFactoredBinaryTrees(Array(2, 4, 5, 10))) // 7
  println(Solution.numFactoredBinaryTrees(Array(18, 3, 6, 2))) // 12
  println(Solution.numFactoredBinaryTrees(Array(2, 4, 16))) // 8
}
