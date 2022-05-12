object leet1466 extends App{
  import scala.collection.mutable._
  object Solution {
    def minReorder(N: Int, connections: Array[Array[Int]]): Int = {
      val Visit = Array.fill(N){0}
      val PointMe = Array.fill(N){Map[Int,Boolean]()}

      for(conn <- connections){
        PointMe(conn(0)) += (conn(1) -> false)
        PointMe(conn(1)) += (conn(0) -> true)
      }

      var ans = 0
      val queue = new Queue[Int]()
      queue += 0
      Visit(0) = 1

      while(queue.nonEmpty){
        val cur = queue.dequeue()
        for(next <- PointMe(cur).keys){
          if(Visit(next) == 0) {
            queue += next
            Visit(next) = 1
            if(!PointMe(cur)(next))
              ans += 1
          }
        }
      }
      ans
    }
  }

  println(Solution.minReorder(6, Array(Array(0,1),Array(1,3),Array(2,3),Array(4,0),Array(4,5))))
  println(Solution.minReorder(5, Array(Array(1,0),Array(1,2),Array(3,2),Array(3,4))))
}
