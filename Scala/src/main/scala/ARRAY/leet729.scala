package ARRAY

// https://leetcode.com/problems/my-calendar-i/

object leet729 extends App {

  class MyCalendar() {
    var schedules = scala.collection.mutable.Map[Int, Int]()

    def book(start: Int, end: Int): Boolean = {
      for (s <- schedules.keys) {
        val e = schedules.getOrElse(s, 0)
        if (end > s && start < e) // 포함되는 조건
          return false
      }

      if(schedules.contains(end)){ // 끝점이 시작점인 schedule을 찾는다.
        schedules(end)
        val temp = schedules(end)
        schedules -= end
        schedules(start) = temp
      }
      else{
        schedules += (start -> end)
      }
      true
    }
  }


  val c = new MyCalendar()
  println(c.book(10, 20))
  println(c.book(15, 25))
  println(c.book(30, 40))
  println(c.book(20, 30))

  /**
   * Your MyCalendar object will be instantiated and called as such:
   * var obj = new MyCalendar()
   * var param_1 = obj.book(start,end)
   */
}
