package STRING

object leet383 extends App{

  import scala.collection.mutable._
  object Solution {
    def canConstruct(ransomNote: String, magazine: String): Boolean = {
      val magazine_map = Map.empty[Char, Int]

      for(char <- magazine){
          if(magazine_map.contains(char)){
            magazine_map(char) += 1
          }
          else{
            magazine_map += (char -> 1)
          }
      }

      for (char <- ransomNote) {
        if (magazine_map.contains(char)) {
       
