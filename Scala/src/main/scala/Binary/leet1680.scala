package Binary

object leet1680 extends App{
  object Solution {
    def concatenatedBinary(N: Int): Int = {
      val MOD = (math.pow(10,9)+7).toInt
      var ans:Long = 0

      (1 to N).map(n => ans = ((ans * math.pow(2, n.toBinaryString.length)).toLong + n)%MOD)

      ans.toInt
    }
  }

  println(Solution.concatenatedBinary(3))
  println(Solution.concatenatedBinary(12))
  println(Solution.concatenatedBinary(42))
}
