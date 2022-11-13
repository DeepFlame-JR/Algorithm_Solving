// https://leetcode.com/problems/time-based-key-value-store/

object leet981 extends App{

  import scala.collection.mutable.Map
  import scala.collection.mutable.TreeMap

  class TimeMap() {
    var map = Map[String, TreeMap[Int, String]]()

    def set(key: String, value: String, timestamp: Int) {
      if (!map.contains(key)) {
        map(key) = TreeMap.empty[Int, String]
      }
      map(key) += (timestamp -> value)
    }

    def get(key: String, timestamp: Int): String = {
      if (map.contains(key)) {
        if (map(key).contains(timestamp)) {
          return map(key)(timestamp)
        } else {
          return map(key).maxBefore(timestamp).map(_._2).getOrElse("")
        }
      }
      ""
    }
  }
}
