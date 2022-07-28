// https://leetcode.com/problems/valid-anagram/

object leet242 extends App {
  object Solution {
    def isAnagram(s: String, t: String): Boolean = {
      if(s.length != t.length)
        return false

      for(char:Char <- s.toSet.toList){
        if(s.count(_ == char) != t.count(_ == char))
          return false
      }
      true
    }
  }

  println(Solution.isAnagram("anagram", "nagaram"))
  println(Solution.isAnagram("rat", "car"))
}
