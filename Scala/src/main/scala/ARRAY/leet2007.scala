package ARRAY

object leet2007 extends App{
  object Solution {
    def findOriginalArray(changed: Array[Int]): Array[Int] = {
      var Counter = scala.collection.mutable.Map[Int, Int]()
      var ans = Array.empty[Int]

      for(num <- changed){
        if(Counter.contains(num))
          Counter(num) += 1
        else
          Counter(num) = 1
      }

      if(Counter.contains(0)){
        val count0 = Counter(0)
        if(count0%2 == 1)
          return Array.empty
        else
          ans = ans ++ Array.fill(count0/2){0}
      }

      for(key <- Counter.keys.toArray.sortWith(_<_)){
        val count = Counter(key)
        if(key > 0 && count > 0){
          if (!Counter.contains(2 * key) || Counter(key) > Counter(2 * key)) // 2배인 수가 없거나 2배인수 개수가 더 적을때
            return Array.empty

          Counter(2 * key) -= count
          ans = ans ++ Array.fill(count) {
            key
          }
        }
      }

      println(ans.mkString(", "))
      ans
    }
  }

  Solution.findOriginalArray(Array(1,3,4,2,6,8))
  Solution.findOriginalArray(Array(6,3,0,1))
  Solution.findOriginalArray(Array(1))
  Solution.findOriginalArray(Array(0,0,0,0))
  Solution.findOriginalArray(Array(5,8,7,8,16,5,16,14,10,10))
}
