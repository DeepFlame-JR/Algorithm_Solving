// https://leetcode.com/problems/find-and-replace-pattern/

object leet890 extends App{
  object Solution {
    def findAndReplacePattern(words: Array[String], pattern: String): List[String] = {
      val map = scala.collection.mutable.Map[Char, Int]()
      var rule = Array.empty[Int]

      var seq = 0
      for (char <- pattern){
        if(!map.exists(_._1==char)) {
          seq += 1
          map += (char -> seq)
        }
        rule :+= map(char)
      }

      def checkWord(word: String):Boolean = {
        val map = scala.collection.mutable.Map[Char, Int]()
        var seq = 0

        for(i <- 0 until word.length){
          val char = word(i)
          if (!map.exists(_._1 == char)) {
            seq += 1
            map += (char -> seq)
          }
          if(rule(i) != map(char))
            return false
        }
        true
      }

      words.filter(checkWord(_)).toList
    }
  }

  Solution.findAndReplacePattern(Array("abc","deq","mee","aqq","dkd","ccc"), "abb").foreach(println)
  Solution.findAndReplacePattern(Array("a","b","c"), "a").foreach(println)

  Solution.findAndReplacePattern(Array("qxrwtncxyoqwmsxoavos", "eqvzjrnqgkezxmqkhdkm", "pjxmgdujohpmtsjhazhs", "yqhlipeqwnylkrqnsbnr", "plktdyslmoptqflowaof"),"ghtxpauhingxekhnoqnk").foreach(println)
}
