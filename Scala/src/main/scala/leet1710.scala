
// https://leetcode.com/problems/maximum-units-on-a-truck/

object leet1710 extends App {
  object Solution {
    def maximumUnits(boxTypes: Array[Array[Int]], truckSize: Int): Int = {
      val sorted_boxTypes = boxTypes.sortBy(-_(1))

      var result = 0
      var space = truckSize
      for(box <- sorted_boxTypes){
        val unit = Math.min(space,box(0))
        result += unit*box(1)

        space -= unit
        if(space == 0)
          return result
      }
      result
    }
  }
}
