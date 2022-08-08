// https://leetcode.com/problems/search-a-2d-matrix-ii/

object leet240 extends App{
  object Solution {
    def searchMatrix(matrix: Array[Array[Int]], target: Int): Boolean = {
      var (x, y) = (0, matrix(0).length-1)

      while(x < matrix.length && y >=0){
        if(matrix(x)(y) == target){
          return true
        }
        else if(target < matrix(x)(y)){ // 아래에는 target보다 큰 수 밖에 없다. 왼쪽으로 이동.
          y -= 1
        }
        else if(target > matrix(x)(y)){ // 아래로 이동.
          x += 1
        }
      }

      false
    }
  }
}
