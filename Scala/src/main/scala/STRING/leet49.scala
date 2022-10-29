package STRING

// https://leetcode.com/problems/group-anagrams/
object leet49 extends App {
        object Solution {
            def groupAnagrams(strs: Array[String]): List[List[String]] = {
                var str_map = scala.collection.mutable.Map[String, Array[String]]()
                
                for(str <- strs){
                    val sorted_str = str.toArray.sortWith(_<_).mkString("")
                    if(str_map.contains(sorted_str)){
                        str_map(sorted_str) :+= str
                    }
                    else{
                        str_map += (sorted_str -> Array(str))
                    }
                }
                
                var ans = Array.empty[List[String]]
                str_map.map(ans :+= _._2.toList)
                ans.toList
            }
        }
}
