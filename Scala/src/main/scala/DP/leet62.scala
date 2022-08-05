package DP

// https://leetcode.com/problems/unique-paths/

object leet62 extends App {
  object Solution {
    def uniquePaths(m: Int, n: Int): Int = {
      val matrix = Array.ofDim[Int](m + 1, n + 1)
      for (j <- 1 to n) {
        for (i <- 1 to m) {
          if (i == 1 || j == 1) {
            matrix(i)(j) = 1
          }
          else {
            matrix(i)(j) = matrix(i - 1)(j) + matrix(i)(j - 1)
          }
        }
      }
      matrix(m)(n)
    }
  }

  println(Solution.uniquePaths(3, 7))
  println(Solution.uniquePaths(3, 2))
  println(Solution.uniquePaths(4, 4))
}
