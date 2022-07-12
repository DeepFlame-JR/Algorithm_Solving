package DP

// https://leetcode.com/problems/interleaving-string/

object leet97 extends App {
  object Solution {
    def isInterleave(s1: String, s2: String, s3: String): Boolean = {
      if (s3.length != s1.length + s2.length)
        return false

      val dp = Array.ofDim[Boolean](s1.length + 1, s2.length + 1)

      for (i <- 0 to s1.length) { // s1의 인덱스
        for (j <- 0 to s2.length) { // s2의 인덱스
          if (i == 0 && j == 0)
            dp(i)(j) = true
          else if (i == 0)
            dp(i)(j) = dp(i)(j - 1) && s2(j - 1) == s3(i + j - 1)
          else if (j == 0)
            dp(i)(j) = dp(i - 1)(j) && s1(i - 1) == s3(i + j - 1)
          else
            dp(i)(j) = dp(i - 1)(j) && s1(i - 1) == s3(i + j - 1) || dp(i)(j - 1) && s2(j - 1) == s3(i + j - 1)
        }
      }

      dp.last.last
    }
  }

  println(Solution.isInterleave(s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"))
  println(Solution.isInterleave(s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"))
  //  println(Solution.isInterleave(s1 = "aabc", s2 = "abad", s3 = "aabadabc"))
  //  println(Solution.isInterleave(s1 = "aabcc", s2 = "dbbca", s3 = "aadbcbbcac"))
  //  println(Solution.isInterleave(s1 = "", s2 = "", s3 = ""))
}
