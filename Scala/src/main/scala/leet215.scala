// https://leetcode.com/problems/kth-largest-element-in-an-array/

object leet215 extends App {
  object Solution {
    def findKthLargest(nums: Array[Int], k: Int): Int = {
      val sorted_nums = nums.sorted.reverse
      sorted_nums(k-1)
    }
  }

  println(Solution.findKthLargest(Array(3,2,1,5,6,4), 2)) // 5
  println(Solution.findKthLargest(Array(3,2,3,1,2,4,5,5,6), 4)) // 4
}
