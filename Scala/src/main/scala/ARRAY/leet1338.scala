package ARRAY

// https://leetcode.com/problems/reduce-array-size-to-the-half/

object leet1338 extends App {

  import scala.collection.mutable._

  object Solution {
    def minSetSize(arr: Array[Int]): Int = {
      val counter = Map[Int, Int]()

      for (num <- arr) {
        if (counter.contains(num))
          counter(num) += 1
        else
          counter(num) = 1
      }

      var ans = counter.keys.toArray.length
      var capa = arr.length / 2 // 지울 수 있는 양
      for (count <- counter.values.toArray.sortWith(_ < _)) {
        capa -= count
        if (capa < 0)
          return ans
        ans -= 1
      }

      ans
    }
  }

  println(Solution.minSetSize(Array(3, 3, 3, 3, 5, 5, 5, 2, 2, 7)))
  println(Solution.minSetSize(Array(7, 7, 7, 7, 7)))

}
