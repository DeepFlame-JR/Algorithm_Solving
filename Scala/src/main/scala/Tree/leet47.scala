object leet47 extends App {
  object Solution{
    def permuteUnique(nums: Array[Int]): List[List[Int]] = {
      val allNums = scala.collection.mutable.Map[Int, Int]()
      for(num <- nums){
        val temp = allNums.getOrElse(num, 0)+1
        allNums += (num -> temp)
      }
      val N = nums.length
      var ans = List[List[Int]]()

      def DFS(li: List[Int]): Unit ={
        if(li.length == N){
          ans :+= li
          return
        }

        // 값을 하나씩 빼면서 진행한다.
        for(key <- allNums.keys){
          if(allNums(key) != 0){
            allNums(key) = allNums(key)-1
            DFS(li :+ key)
            allNums(key) = allNums(key)+1
          }
        }
      }

      DFS(List.empty[Int])
      ans
    }
  }

  println(Solution.permuteUnique(Array(1,1,2)))
  println(Solution.permuteUnique(Array(1,2,3)))
  println(Solution.permuteUnique(Array(0,1)))
  println(Solution.permuteUnique(Array(0)))
}
