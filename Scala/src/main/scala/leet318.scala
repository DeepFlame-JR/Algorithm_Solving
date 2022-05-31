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

        fo
