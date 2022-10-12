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

      val ans = char_unique_list.min
      if (ans < MAX_VALUE) ans else -1
    }
  }

  object Solution2 {
    def firstUniqChar(s: String): Int = {
      val Counter = scala.collection.mutable.Map.empty[Char, Int]
      s.distinct.toCharArray.map(x => Counter += (x -> s.count(_==x)))

      for(i <- s.indices){
        val char = s(i)
        if(Counter(char) == 1)
          return i
      }
      -1
    }
  }

  println(Solution.firstUniqChar("leetcode"))
  println(Solution.firstUniqChar("loveleetcode"))
  println(Solution.firstUniqChar("aabb"))
}
