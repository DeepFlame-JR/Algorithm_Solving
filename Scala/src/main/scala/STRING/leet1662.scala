package STRING

// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

object leet1662 extends App{
  object Solution {
    def arrayStringsAreEqual(word1: Array[String], word2: Array[String]): Boolean = {
      word1.flatten.mkString("") == word2.flatten.mkString("")
    }
  }
}
