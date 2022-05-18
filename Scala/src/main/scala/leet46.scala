// https://leetcode.com/problems/permutations/
object leet46 extends App{
  object Solution {
      def permute(nums: Array[Int]): List[List[Int]] = {
        if(nums.length <= 1){
          List(nums.toList)
        }
        else{
          nums.toList.flatMap(n => permute(nums.filter(_ != n)).map(n :: _))
        }
      }

    /*
    def permute(nums: Array[Int]): List[List[Int]] = {
      val N = nums.length
      val Visit = Array.fill(N){0}
      var ans = List[List[Int]]()

      def DFS(index: Int, li:List[Int]): Unit = {
        if(li.length == N){
          ans = ans :+ li
          return
        }

        for(i <- 0 until N){
          if(i != index && Visit(i) == 0){
            Visit(i) = 1
            DFS(i, li :+ nums(i))
            Visit(i) = 0
          }
        }
      }
      DFS(-1, List[Int]())
      ans
    }
    */
  }

  println(Solution.permute(Array(1,2,3)))
  println(Solution.permute(Array(0,1)))
  println(Solution.permute(Array(0)))
}
