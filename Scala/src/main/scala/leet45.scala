// https://leetcode.com/problems/jump-game-ii/
object leet45 extends App {
  object Solution {
    def jump(nums: Array[Int]): Int = {
      if(nums.length == 1) return 0
      val max_value = 100000

      val available = Array.fill(nums.length){0}
      for(i <- nums.length-2 to 0 by -1){
        if(nums(i) == 0) {
          available(i) = max_value
        } else{
          available(i) = available.slice(i+1, math.min(available.length, i+nums(i)+1)).min +1
        }
      }
      available(0)
    }
  }

  println(Solution.jump(Array(2,3,1,1,4)))
  println(Solution.jump(Array(2,3,0,1,4)))
  println(Solution.jump(Array(2,3,100,1,4)))
  println(Solution.jump(Array(0)))
}
