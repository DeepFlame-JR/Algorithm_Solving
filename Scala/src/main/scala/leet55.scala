object leet55 extends App{
  object Solution {
    def canJump(nums: Array[Int]): Boolean = {
      if(nums.length == 1) return true

      var last_position = nums.length-1
      for(i <- nums.length-2 to 0 by -1){
        if(i+nums(i) >= last_position)
          last_position = i
      }
      last_position==0
    }
  }

  println(Solution.canJump(Array(2,3,1,1,4)))
  println(Solution.canJump(Array(3,2,1,0,4)))
  println(Solution.canJump(Array(2,0,3,2,1,0,4)))
  println(Solution.canJump(Array(0,3,2,4)))
  println(Solution.canJump(Array(3,1,0,2,0,0)))
  println(Solution.canJump(Array(2,0,0)))
}
