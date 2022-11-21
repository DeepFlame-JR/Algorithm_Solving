package ARRAY

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

object leet1578 extends App {
  object Solution {
    def minCost(colors: String, neededTime: Array[Int]): Int = {
      val N = neededTime.length
      if (N == 1)
        return 0

      val color_list = colors.toArray

      var ans = 0
      var prev_index = 0
      var cur_index = 1
      while (cur_index < N) {
        val prev = color_list(prev_index)
        val cur = color_list(cur_index)

        if (prev == cur) {
          if (neededTime(prev_index) <= neededTime(cur_index)) {
            ans += neededTime(prev_index)
            neededTime(prev_index) = 0
            prev_index += 1
          } else {
            ans += neededTime(cur_index)
            neededTime(cur_index) = 0
          }
        }
        else {
          prev_index += 1
        }

        cur_index += 1
        while (prev_index < N && neededTime(prev_index) == 0) {
          prev_index += 1
        }
      }

      ans
    }
  }
}
