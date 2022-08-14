package ARRAY

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

object leet378 extends App{
  object Solution {
    def kthSmallest(matrix: Array[Array[Int]], k: Int): Int = {
      val N = matrix.length
      val Visit = Array.ofDim[Boolean](N, N)

      val pq = scala.collection.mutable.PriorityQueue[Array[Int]]()(Ordering.by(-_(0)))

      pq.enqueue(Array(matrix(0)(0), 0, 0))
      Visit(0)(0) = true

      var index = 0
      while(pq.nonEmpty){
        val cur = pq.dequeue()
        index += 1

        if(index == k)
          return cur(0)

        val (x, y) = (cur(1), cur(2))
        if(x+1 < N && !Visit(x+1)(y)) {
          pq.enqueue(Array(matrix(x+1)(y), x+1, y))
          Visit(x+1)(y) = true
        }
        if(y+1 < N && !Visit(x)(y+1)) {
          pq.enqueue(Array(matrix(x)(y+1), x, y+1))
          Visit(x)(y+1) = true
        }
      }
      0
    }
  }

  println(Solution.kthSmallest(Array(Array(1,5,9),Array(10,11,13),Array(12,13,15)), 8))
}
