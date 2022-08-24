package STRING

// https://leetcode.com/problems/number-of-matching-subsequences/
object leet792 extends App {
  object Solution {
    def numMatchingSubseq(s: String, words: Array[String]): Int = {
      val waiting = scala.collection.mutable.Map[Int, Array[Array[Int]]]()

      for (char <- '`' to 'z') // `, a ~ z
        waiting(char) = Array.empty[Array[Int]]

      for (i <- 0 until words.length) { // word의 가장 앞자리를 기다리는 Map 변수
        waiting(words(i).head) :+= Array(i, 1)
      }

      for (i <- 0 until s.length) {
        val process = waiting(s(i)).clone()
        waiting(s(i)) = waiting(s(i)).drop(process.length)

        if (process.length > 0) {
          for (pro <- process) {
            val word = words(pro(0))
            if (word.length == pro(1)) // 만약 해당 자리가 마지막 자리라면 기다리는 글자가 없는 것
              waiting('`') :+= Array(0)
            else // 다음 것을 기다린다
              waiting(word(pro(1))) :+= Array(pro(0), pro(1) + 1)
          }
        }
      }

      waiting('`').length
    }
  }

  println(Solution.numMatchingSubseq("abcde", Array("a", "bb", "acd", "ace"))) // 3
  println(Solution.numMatchingSubseq("dsahjpjauf", Array("ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"))) // 2
}
