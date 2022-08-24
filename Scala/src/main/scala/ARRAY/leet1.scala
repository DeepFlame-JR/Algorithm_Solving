package ARRAY

// https://leetcode.com/problems/two-sum/
object leet1 extends App {
  object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
      val num_index = scala.collection.mutable.HashMap[Int, Int]()

      var i = 0
      while (!num_index.contains(target - nums(i))) {
        num_index(nums(i)) = i
        i += 1
      }
      Array(num_index(target - nums(i)), i)
    }
  }

  Solution.twoSum(Array(2, 7, 11, 15), 9).foreach(println)
  Solution.twoSum(Array(3, 2, 4), 6).foreach(println)
  Solution.twoSum(Array(3, 3), 6).foreach(println)
}
