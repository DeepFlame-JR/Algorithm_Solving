
// https://leetcode.com/problems/queue-reconstruction-by-height/

object leet406 extends App {
  object Solution {
    def reconstructQueue(people: Array[Array[Int]]): Array[Array[Int]] = {
      var result = Array[Array[Int]]()

      // 키가 큰 순서대로 먼저 배치한다
      // 그 후 작은 애들을 배치하면 큰 애들에 대해 상관을 쓰지 않아도 된다
      for(person <- people.sortBy(_(1)).sortBy(-_(0))){
        val seq = person(1)
        result = result.take(seq) ++ Array(person) ++ result.drop(seq)
      }

      result
    }
  }

  Solution.reconstructQueue(Array(Array(7,0),Array(4,4),Array(7,1),Array(5,0),Array(6,1),Array(5,2)))
}
