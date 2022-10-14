package ARRAY

// https://leetcode.com/problems/increasing-triplet-subsequence/

object leet334 extends App{
  object Solution {
    def increasingTriplet(nums: Array[Int]): Boolean = {
      var min1 = math.pow(2,31)
      var min2 = math.pow(2,31)

      for(num <- nums){
        if(num <= min1){
          min1 = math.min(min1, num)
        }
        else if(num <= min2){
          min2 = math.min(min2, num)
        }
        else{
          return true
        }
      }
      false
    }
  }
}
