package STRING

// https://leetcode.com/problems/length-of-last-word/

object leet58 extends App {
  object Solution {
    def lengthOfLastWord(s: String): Int = {
      s.trim().split(" ").last.length
    }
  }

  println(Solution.lengthOfLastWord("Hello World"))
  println(Solution.lengthOfLastWord("   fly me   to   the moon  "))
  println(Solution.lengthOfLastWord("luffy is still joyboy"))
}
