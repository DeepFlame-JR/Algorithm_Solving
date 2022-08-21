package DP

// https://leetcode.com/problems/min-cost-climbing-stairs/

object leet746 {
  object Solution {
    def minCostClimbingStairs(cost: Array[Int]): Int = {
      val costs = cost ++ Array(0)
      val dp = Array.fill(costs.length) {
        0
      }
      dp(0) = cost(0)
      dp(1) = cost(1)

      for (i <- 2 until costs.length) {
        dp(i) = math.min(dp(i - 1), dp(i - 2)) + costs(i)
      }
      dp(costs.length - 1)
    }
  }
}
