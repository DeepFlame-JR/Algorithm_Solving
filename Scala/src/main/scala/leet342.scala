
// https://leetcode.com/problems/power-of-four/

object leet342 extends App{
  object Solution {
    def isPowerOfFour(n: Int): Boolean = {
      if(n == 1) return true
      if(n%10 != 4 && n%10 != 6) return false

      var temp = n
      while(temp >= 4){
        if(temp%4 > 0) return false
        temp /= 4
      }

      temp == 1
    }
  }

  println(Solution.isPowerOfFour(16))
  println(Solution.isPowerOfFour(5))
  println(Solution.isPowerOfFour(1))

  var a = Array(4,2,5)
  a = a.sortWith(_<_)
  println(a.mkString(", "))
}
