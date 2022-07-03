package DP

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

object leet122 extends App {
  object Solution {
    def maxProfit(prices: Array[Int]): Int = {
      var (i, buy, ans) = (0,0,0)
      val N = prices.length-1

      while(i < N){
        // 내려갈 수 있는 값까지 내려가서 산다
        while(i < N && prices(i+1)<=prices(i)) i += 1
        buy = prices(i)

        // 올라갈 수 있는 값까지 올라가서 산다
        while(i < N && prices(i+1)>prices(i)) i += 1
        ans += prices(i) - buy
      }

      ans
    }
  }

  println(Solution.maxProfit(Array(7,1,5,3,6,4)))
  println(Solution.maxProfit(Array(1,2,3,4,5)))
  println(Solution.maxProfit(Array(7,6,4,3,1)))
  println(Solution.maxProfit(Array(2,2,5)))
  println(Solution.maxProfit(Array(2,5,5)))
  println(Solution.maxProfit(Array(2,1,2,0,1)))

}
