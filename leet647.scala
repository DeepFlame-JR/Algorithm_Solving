// https://leetcode.com/problems/palindromic-substrings/

object leet647 extends App{
  import scala.collection.mutable._
  object Solution {
    def countSubstrings(s: String): Int = {
      val map = Map[Char, List[Int]]()
      for(i <- 0 until s.length){
        val word = s(i)
        if(map.exists(_._1==word))
          map(word) = map(word) :+ i
        else
          map += (word -> List(i))
      }

      var ans = s.length
      for(start <- 0 until s.length){
        val word = s(start)
        for(same_word_index <- map(word)){
          if(same_word_index > start && s.substring(start,same_word_index+1) == s.substring(start,same_word_index+1).reverse)
            ans += 1
        }
      }
      ans
    }
  }

  object Solution2 {
    def countSubstrings(s: String): Int = {
      var ans = 0
      def extendPalindrum(l:Int, r:Int): Unit ={
        var (left, right) = (l, r)
        while(left >= 0 && right < s.length && s.substring(left, right+1) == s.substring(left, right+1).reverse) {
          ans += 1 ; left -= 1 ; right += 1
        }
      }

      for(i <- 0 until s.length){
        extendPalindrum(i, i) // a => bab
        extendPalindrum(i, i+1) // aa => baab
      }
      ans
    }
  }

  println(Solution2.countSubstrings("abc"))
  println(Solution2.countSubstrings("aaa"))
  println(Solution2.countSubstrings("aba"))
}
