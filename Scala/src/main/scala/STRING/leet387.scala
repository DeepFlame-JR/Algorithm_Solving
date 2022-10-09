package STRING

object leet387 extends App{
  object Solution {
    def firstUniqChar(s: String): Int = {
      val MAX_VALUE = 100001
      val char_unique_list = Array.fill(26){MAX_VALUE} // char이 유일한지 확인한다.

      for(i <- s.indices){
        val ord = s(i) - 'a' // char 인덱스화
        if(char_unique_list(ord) == MAX_VALUE)
          char_unique_list(ord) = i
        else if(char_unique_list(ord) < MAX_VALUE)
          char_unique_list(ord) = MAX_VALUE + 1
      }

      val ans = char_unique_l
