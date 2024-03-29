package STRING

object leet557 extends App{
  object Solution {
    def reverseWords(s: String): String = {
      s.split(' ').map(_.reverse).mkString(" ")
    }

    def reverseWords2(s: String): String = {
      val stack = scala.collection.mutable.Stack[Char]()
      var ansList = Array.empty[String]

      for(char <- s){
        if(char == ' '){
          var temp = ""
          while(stack.nonEmpty){
            temp += stack.pop()
          }
          ansList :+= temp
        }
        else{
          stack.push(char)
        }
      }


      if(stack.nonEmpty){
        var temp = ""
        while (stack.nonEmpty) {
          temp += stack.pop()
        }
        ansList :+= temp
      }

      ansList.mkString(" ")
    }
  }

  println(Solution.reverseWords("Let's take LeetCode contest"))
}
