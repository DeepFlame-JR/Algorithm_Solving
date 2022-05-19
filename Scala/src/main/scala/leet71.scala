//https://leetcode.com/problems/simplify-path/

import scala.collection.mutable

object leet71 extends App{
  object Solution {
    def simplifyPath(path: String): String = {
      val dir_list = path.split('/')
      val stack = mutable.Stack[String]()

      for(dir <- dir_list){
        if(dir == "..") {
          if(stack.nonEmpty)
            stack.pop()
        } else if(dir != "." && dir.nonEmpty) {
          stack.push(dir)
        }
      }

      if(stack.isEmpty) return "/"
      var ans = ""
      while(stack.nonEmpty){
        ans = "/"+ stack.pop() + ans
      }
      ans
    }
  }
  println(Solution.simplifyPath("/home/"))
  println(Solution.simplifyPath("/../"))
  println(Solution.simplifyPath("/home//foo/"))
  println(Solution.simplifyPath("/a/./b/../../c/"))
}
