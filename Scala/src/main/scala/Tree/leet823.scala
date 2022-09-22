package Tree

// https://leetcode.com/problems/binary-trees-with-factors/

object leet823 extends App{
  object Solution {
    def numFactoredBinaryTrees(arr: Array[Int]): Int = {
      val MOD = math.pow(10, 9).toInt + 7
      val sorted_arr = arr.sortWith(_ < _)
      val dp = scala.collection.mutable.Map[Int, Long]()

      for (n <- sorted_arr) {
        dp += (n -> 1)
      }

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
}
