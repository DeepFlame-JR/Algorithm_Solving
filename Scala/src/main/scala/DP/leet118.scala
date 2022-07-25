package DP

// https://leetcode.com/problems/pascals-triangle/

object leet118 extends App {
  object Solution {
    def generate(numRows: Int): List[List[Int]] = {
      var ans = Array(List(1))

      for (n <- 1 until numRows) {
        var cur = List.fill(n + 1) {
          1
        }
        for (i <- 1 until n) {
          cur = cur.updated(i, ans(n - 1)(i - 1) + ans(n - 1)(i))
        }
        ans :+= cur
      }

      ans.toList
    }
  }

  Solution.generate(1)
  Solution.generate(5)
}
