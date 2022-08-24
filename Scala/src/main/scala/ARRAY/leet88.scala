package ARRAY

// https://leetcode.com/problems/merge-sorted-array/

object leet88 extends App {
  object Solution {
    def merge(nums1: Array[Int], m: Int, nums2: Array[Int], n: Int): Unit = {
      var (p1, p2) = (m, n)

      while (p1 > 0 && p2 > 0) {
        if (nums1(p1 - 1) > nums2(p2 - 1)) {
          nums1.update(p1 + p2 - 1, nums1(p1 - 1))
          p1 -= 1
        }
        else {
          nums1.update(p1 + p2 - 1, nums2(p2 - 1))
          p2 -= 1
        }
      }
      // 앞 부분 바꿔줘야 한다.
      while (p2 > 0) {
        nums1.update(p2 - 1, nums2(p2 - 1))
        p2 -= 1
      }
    }
  }

  Solution.merge(Array(1, 2, 3, 0, 0, 0), 3, Array(2, 5, 6), 3)
  Solution.merge(Array(4, 5, 6, 0, 0, 0), 3, Array(1, 2, 3), 3)
}
