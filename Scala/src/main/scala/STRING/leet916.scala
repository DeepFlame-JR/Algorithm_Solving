package STRING

// https://leetcode.com/problems/word-subsets/
object leet916 extends App {

  import scala.collection.mutable._

  object Solution {
    def createWordCounter(): Map[Char, Int] = {
      val wordCouterMap = Map.empty[Char, Int]
      ('a' to 'z').foreach(x => wordCouterMap += (x -> 0))
      wordCouterMap
    }

    def wordSubsets(words1: Array[String], words2: Array[String]): List[String] = {
      val max_counter = createWordCounter()

      for (word2 <- words2) {
        val temp = createWordCounter()
        word2.toList.foreach(x => temp(x) += 1)
        temp.foreach(x => max_counter(x._1) = math.max(max_counter(x._1), x._2))
      }

      def Check(word: String): Boolean = {
        val temp = createWordCounter()
        word.toList.foreach(x => temp(x) += 1)
        for (item <- max_counter) {
          if (temp(item._1) < item._2)
            return false
        }
        true
      }

      words1.filter(Check(_)).toList
    }
  }

  println(Solution.wordSubsets(Array("amazon", "apple", "facebook", "google", "leetcode"), Array("e", "o")))
  println(Solution.wordSubsets(Array("amazon", "apple", "facebook", "google", "leetcode"), Array("lo", "eo")))
}
