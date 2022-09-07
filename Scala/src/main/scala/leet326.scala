// https://leetcode.com/problems/power-of-three/
object leet326 extends App{
  object Solution {
    def isPowerOfThree(n: Int): Boolean = {
      if (n == 1) return true

      var temp = n
      while (temp >= 3) {
        if (temp % 3 > 0) return false
        temp /= 3
      }

      temp == 1
    }
  }

  println(Solution.isPowerOfThree(27))
  println(Solution.isPowerOfThree(0))
  println(Solution.isPowerOfThree(9))
}
