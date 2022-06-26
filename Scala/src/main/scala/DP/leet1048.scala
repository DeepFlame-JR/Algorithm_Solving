package DP

// https://leetcode.com/problems/longest-string-chain/

import scala.collection.mutable.Map

object leet1048 extends App {
  object Solution {
    def longestStrChain(words: Array[String]): Int = {
      var ans = 1

      val sorted_words = words.sortBy(_.length)
      val dp = Map.empty[String, Int]
      for (word <- sorted_words) {
        var local_max = 1
        for (i <- 0 until word.length) {
          // 이전 값의 후보를 구해본다
          val prev_candidate = word.substring(0, i) + word.substring(i + 1, word.length)
          local_max = math.max(local_max, dp.getOrElse(prev_candidate, 0) + 1)
        }
        dp += (word -> local_max)
        ans = math.max(ans, local_max)
      }

      ans
    }
  }

  println(Solution.longestStrChain(Array("a", "b", "ba", "bca", "bda", "bdca")))
  println(Solution.longestStrChain(Array("xbc", "pcxbcf", "xb", "cxbc", "pcxbc")))
  println(Solution.longestStrChain(Array("abcd", "dbqca")))
}
