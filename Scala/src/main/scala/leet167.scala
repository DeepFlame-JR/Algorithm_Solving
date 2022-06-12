
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

import scala.collection.mutable

object leet167 extends App {
  object Solution {
    def twoSum(numbers: Array[Int], target: Int): Array[Int] = {
      val value_index = mutable.Map[Int, Int]()

      for(i <- 0 until numbers.length){
        val sub = target-numbers(i)
        if(value_index.exists(_._1 == sub)){
          return Array(value_index(sub), i+1)
        }
        value_index += (numbers(i) -> (i+1))
      }

      Array(0,0)
    }
  }

  println(Solution.twoSum(Array(2,7,11,15),9).mkString(", "))
  println(Solution.twoSum(Array(2,3,4),6).mkString(", "))
  println(Solution.twoSum(Array(-1,0),-1).mkString(", "))

}
