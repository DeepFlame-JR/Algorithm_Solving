package DP

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// 2X2 DP

object leet718 extends App {
  object Solution {
    def findLength(nums1: Array[Int], nums2: Array[Int]): Int = {
      val N = nums1.length
      val M = nums2.length
      val DP = Array.ofDim[Int](N + 1, M + 1) // 행 nums1의 i번째 행을 비교함
      var ans = 0

      for (i <- 1 to N) {
        for (j <- 1 to M) {
          if (nums1(i - 1) == nums2(j - 1)) {
            DP(i)(j) = DP(i - 1)(j - 1) + 1 // i-1: 이전 시도, j-1: 앞에 숫자
          }
          else {
            DP(i)(j) = 0
          }
          ans = math.max(ans, DP(i)(j))
        }
      }

      ans
    }
  }

  println(Solution.findLength(Array(1, 2, 3, 2, 1), Array(3, 2, 1, 4, 7)))
  println(Solution.findLength(Array(1, 2, 3, 2, 1), Array(3, 2, 3, 2, 1)))
  println(Solution.findLength(Array(0, 0, 0, 0, 0), Array(0, 0, 0, 0, 0)))
  println(Solution.findLength(Array(1, 0, 0, 0, 1), Array(1, 0, 0, 1, 1)))

}
