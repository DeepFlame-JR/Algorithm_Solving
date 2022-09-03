package ARRAY

// https://leetcode.com/problems/longest-increasing-subsequence/

object leet300 extends App {
  object Solution {
    def lengthOfLIS(nums: Array[Int]): Int = {
      val map = scala.collection.mutable.Map[Int, Int]()

      for (num <- nums) {
        val lower_array = map.toArray.filter(_._1 < num)

        if (lower_array.isEmpty) {
          map += (num -> 1)
        }
        else {
          val max_count = lower_array.maxBy(_._2)._2
          map(num) = max_count + 1
        }
      }

      map.toArray.maxBy(_._2)._2
    }
  }

  println(Solution.lengthOfLIS(Array(10,9,2,5,3,7,101,18)))
  println(Solution.lengthOfLIS(Array(0,1,0,3,2,3)))
  println(Solution.lengthOfLIS(Array(7,7,7,7,7,7)))

  Array(1,2,3).filter(_<6)
}
