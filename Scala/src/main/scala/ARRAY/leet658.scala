package ARRAY

// https://leetcode.com/problems/find-k-closest-elements/

object leet658 extends App {
  object Solution {
    def findClosestElements(arr: Array[Int], k: Int, x: Int): List[Int] = {
      var ans = Array.empty[Int]
      var counter = scala.collection.mutable.Map[Int, Array[Int]]()

      for(n <- arr){
        val diff = math.abs(n - x)
        if(counter.contains(diff)){
          counter(diff) :+= n
        }
        else{
          counter(diff) = Array(n)
        }
      }

      val sorted_keys = counter.keys.toArray.sortWith(_<_)
      var i = 0
      while(ans.length < k){
        ans = ans ++ counter(sorted_keys(i))
        i += 1
      }

      ans.take(k).sortWith(_<_).toList
    }
  }
}
