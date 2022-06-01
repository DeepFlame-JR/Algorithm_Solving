// https://leetcode.com/problems/maximum-product-of-word-lengths/
// 비트 연산

object leet318 extends App{
  object Solution {
    def maxProduct(words: Array[String]): Int = {
      var ans:Int = 0
      var bitset_list = List.fill(words.length){0}

      for(i <- 0 until words.length){
        val word = words(i)
        val word_length = word.length
        var bitset = 0

        // abd > 1101, bef > 11010
        for(char <- word){
          bitset |= 1 << (char.toInt-97)
        }

        for(j <- 0 until i) {
          // 같은 자리에 1이 하나라도 있다면 1보다 큼
          if ((bitset_list(j) & bitset) == 0) {
            ans = math.max(ans, word_length * words(j).length)
          }
        }
        bitset_list = bitset_list.updated(i, bitset)
      }

      ans
    }
  }

  println(Solution.maxProduct(Array("abcw","baz","foo","bar","xtfn","abcdef")))
  println(Solution.maxProduct(Array("a","ab","abc","d","cd","bcd","abcd")))
  println(Solution.maxProduct(Array("a","aa","aaa","aaaa")))
}
