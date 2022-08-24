package ARRAY

// https://leetcode.com/problems/course-schedule-iii/
object leet630 extends App {
  object Solution {
    def scheduleCourse(courses: Array[Array[Int]]): Int = {
      val sorted_courses = courses.sortBy(_ (0)).sortBy(_ (1))

      val pq = scala.collection.mutable.PriorityQueue[Int]()
      var days = 0
      for (course <- sorted_courses) {
        val duration = course(0)
        if (duration + days <= course(1)) {
          pq.enqueue(duration)
          days += duration
        }
        else if (pq.nonEmpty && pq.head > duration) {
          days -= pq.dequeue()
          pq.enqueue(duration)
          days += duration
        }
      }
      pq.length
    }
  }

  println(Solution.scheduleCourse(Array(Array(100, 200), Array(200, 1300), Array(1000, 1250), Array(2000, 3200))))
  println(Solution.scheduleCourse(Array(Array(100, 200), Array(1000, 1300), Array(200, 1350), Array(200, 1350))))
}
