

// https://leetcode.com/problems/range-sum-query-mutable/

object leet307 extends App{

  class NumArray(_nums: Array[Int]) {
    val arr: Array[Int] = _nums
    val len: Int = arr.length
    var s: Int = arr.sum

    def update(index: Int, `val`: Int) {
      s -= arr(index)
      arr(index) = `val`
      s += arr(index)
    }

    // Memory Limit Exceeded 피하기
    def sumRange(left: Int, right: Int): Int = {
      if(right-left < len/2){ // 길이가 비교적 짧다
        return arr.slice(lef
