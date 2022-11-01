package ARRAY

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

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
}
