package ARRAY

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

object leet34 extends App {
  object Solution {
    def searchRange(nums: Array[Int], target: Int): Array[Int] = {
      var (ans_s, ans_e) = (100000, -1)

      def helper(start: Int, end: Int): Unit = {
        if (start > end)
          return

        val mid = (start + end) / 2

        if (nums(mid) == target) {
          ans_s = math.min(ans_s, mid)
          ans_e = math.max(ans_e, mid)
        }

        if (mid - 1 >= 0 && target <= nums(mid - 1)) {
          helper(start, mid - 1)
        }
        if (mid + 1 < nums.length && target >= nums(mid + 1)) {
          helper(mid + 1, end)
        }
      }

      helper(0, nums.length - 1)

      if (ans_s == 100000)
        ans_s = -1

      Array(ans_s, ans_e)
    }
  }

  Solution.searchRange(Array(5, 7, 7, 8, 8, 10), 8) // 3,4
  Solution.searchRange(Array(5, 7, 7, 8, 8, 10), 6) // -1,-1
  Solution.searchRange(Array(), 8) // 3,4
}
