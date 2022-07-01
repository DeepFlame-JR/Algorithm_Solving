package DP

// https://leetcode.com/problems/jump-game-ii/
object leet45 extends App {
  object Solution {
    def jump(nums: Array[Int]): Int = {
      if (nums.length == 1) return 0
      val max_value = 100000

      val available = Array.fill(nums.length) {
        0
      }
      for (i <- nums.length - 2 to 0 by -1) {
        if (nums(i) == 0) {
          available(i) = max_value
        } else {
          // i+1 ~ i+1+(점프할 수 있는 길이) 중 가장 적은 횟수를 불러온다
          available(i) = available.slice(i + 1, math.min(available.length, i + 1 + nums(i))).min + 1
        }
      }
      available(0)
    }
  }

  println(Solution.jump(Array(2, 3, 1, 1, 4)))
  println(Solution.jump(Array(2, 3, 0, 1, 4)))
  println(Solution.jump(Array(2, 3, 100, 1, 4)))
  println(Solution.jump(Array(0)))
}
