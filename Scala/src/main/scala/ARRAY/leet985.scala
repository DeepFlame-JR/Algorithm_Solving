package ARRAY

object leet985 extends App{
  object Solution {
    def sumEvenAfterQueries(nums: Array[Int], queries: Array[Array[Int]]): Array[Int] = {
      var ans = Array.empty[Int]
      var even_sum = nums.filter(_%2==0).sum

      for(query <- queries){
        if(nums(query(1))%2 == 0)
          even_sum -= nums(query(1))

        nums(query(1)) += query(0)
        if(nums(query(1))%2 == 0)
          even_sum += nums(query(1))

        ans :+= even_sum
      }

      ans
    }
  }

  println(Solution.sumEvenAfterQueries(Array(1), Array(Array(4,0))).mkString(", "))
}
