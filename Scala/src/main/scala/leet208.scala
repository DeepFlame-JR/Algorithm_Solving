object leet208 extends App {
  import scala.collection.mutable

  class TrieNode(){
    var children: mutable.Map[Char, TrieNode] = mutable.Map()
    var is_word = false
  }

  class Trie() {
    val root = new TrieNode()

    def insert(word: String) {
      var cur = root
      for(w <- word){
        if(!cur.children.exists(_._1==w))
          cur.children(w) = new TrieNode()
        cur = cur.children(w)
      }
      cur.is_word = true
    }

    def search(word: String): Boolean = {
      var cur = root
      for(w <- word){
        if(!cur.children.exists(_._1==w)){
          return false
        }
        cur = cur.children(w)
      }
      cur.is_word
    }

    def startsWith(prefix: String): Boolean = {
      var cur = root
      for(w <- prefix){
        if(!cur.children.exists(_._1==w)){
          return false
        }
        cur = cur.children(w)
      }
      true
    }
  }

  // Your Trie object will be instantiated and called as such:
  var obj = new Trie()
  obj.insert("apple")
  var p1 = obj.search("apple")
  var p2 = obj.startsWith("app")
  var p3 = obj.startsWith("app1")
  println(p1 + " " + p2 + " " + p3)

}
