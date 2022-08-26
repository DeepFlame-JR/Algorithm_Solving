package ARRAY

// https://leetcode.com/problems/reordered-power-of-2/

object leet869 extends App {
  object Solution {
    def reorderedPowerOf2(n: Int): Boolean = {
      if (n == 1) return true

      def Check2(number: Int): Boolean = {
        var cur = number
        while (cur != 1) {
          if (cur % 2 == 1)
            return false
          cur /= 2
        }
        true
      }

      var n_arr = Array.empty[Int]
      for (char <- n.toString) {
        n_arr :+= char.toString.toInt
      }

      for (pcase <- n_arr.permutations) {
        val number = pcase.mkString
        if (number(0) != '0') {
          if (Check2(number.toInt)) {
            return true
          }
        }
      }

      false
    }
  }

  println(Solution.reorderedPowerOf2(10))
  println(Solution.reorderedPowerOf2(4201))
}
