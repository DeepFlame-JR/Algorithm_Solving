package DP

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

object leet121 extends App {
  object Solution {
    def maxProfit(prices: Array[Int]): Int = {
      var (ans, buy) = (0, prices(0))

      for (price <- prices) {
        buy = math.min(buy, price)
        ans = math.max(ans, price - buy)
      }
      ans
    }
  }

  println(Solution.maxProfit(Array(7, 1, 5, 3, 6, 4)))
  println(Solution.maxProfit(Array(7, 1, 5, 3, 6, 4, 19, 0, 40)))
  println(Solution.maxProfit(Array(7, 6, 4, 3, 1)))
  println(Solution.maxProfit(Array(7, 10, 19, 4)))
}
