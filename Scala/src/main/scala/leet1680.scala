// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

object leet1680 extends App{
  object Solution {
    def concatenatedBinary(N: Int): Int = {
      val MOD = (math.pow(10, 9) + 7).toInt
      var ans: Long = 0

      (1 to N).map(n => ans = ((ans * math.pow(2, n.toBinaryString.length)).toLong + n) % MOD)

      ans.toInt
    }
  }
}
