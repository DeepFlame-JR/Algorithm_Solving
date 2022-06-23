// https://leetcode.com/problems/furthest-building-you-can-reach/

object leet1642 extends App {
  import scala.collection.mutable

  object Solution {
    def furthestBuilding(heights: Array[Int], bricks: Int, ladders: Int): Int = {
      val pq = mutable.PriorityQueue.empty[Int].reverse
      var b = bricks

      for(i <- 0 until heights.length-1){
        val diff = heights(i+1)-heights(i)

        if(diff > 0) {
          pq.enqueue(diff)      // 우선순위 큐에 삽입

          if(pq.size > ladders) // 사다리를 다 사용했을 때
            b -= pq.dequeue()   // 가장 벽돌을 적게 사용하고 사다리를 확보한다

          if(b < 0)             // 만약 벽돌을 모두 사용했다면 다음 단계에 도달할 수 없다
            return i
        }
      }
      heights.length-1
    }
  }

  println(Solution.furthestBuilding(Array(4,2,7,6,9,14,12), 5, 1))
  println(Solution.furthestBuilding(Array(4,12,2,7,3,18,20,3,19), 10, 2))
  println(Solution.furthestBuilding(Array(14,3,19,3), 17, 0))
  println(Solution.furthestBuilding(Array(1,5,1,2,3,4,10000), 3, 1))

}
