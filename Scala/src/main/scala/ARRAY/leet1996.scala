package ARRAY

object leet1996 extends App{
  object Solution {
    def numberOfWeakCharacters(properties: Array[Array[Int]]): Int = {
      var ans = 0
      val sorted_properties = properties.sortBy(_(1)).sortBy(-_(0)) // defense로 오름차순 attack으로 내림차순

      var strongMan_attack = 0
      var strongMan_defense = 0
      for(property <- sorted_properties){
        val attack = property(0)
        val defense = property(1)

        if(attack < strongMan_attack && defense < strongMan_defense){
          ans += 1
        }
        else if(defense > strongMan_defense){
          strongMan_attack = attack
          strongMan_defense = defense
        }
      }

      ans
    }
  }
}
