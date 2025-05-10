import 'dart:io';

class Tire {
  Map<String, Tire> child = {};
  String val = "";
  bool is_root = false;

  void append(String word, String val) {
    this.val = val;
    if (!word.isEmpty) {
      child
          .putIfAbsent(word[0], () => Tire())
          .append(word.substring(1), val + word[0]);
    } else {
      is_root = true;
    }
  }

  String match(String word) {
    if (!word.isEmpty) {
      if (child.containsKey(word[0])) {
        if (child[word[0]]!.is_root) {
          return word[0];
        } else {
          return word[0] + child[word[0]]!.match(word.substring(1));
        }
      }
    }
    return word;
  }

  @override
  String toString() {
    String output = "current: ${val} \t is_root ${is_root} \t child: ";
    for (var entry in child.entries) {
      output += (entry.key + " ");
    }
    output += "\n";
    for (var entry in child.entries) {
      output += entry.value.toString();
    }
    return output;
  }
}

class Solution {
  Tire root_tree = Tire();

  String replaceWords(List<String> dictionary, String sentence) {
    for (var root in dictionary) {
      root_tree.append(root, "");
    }
    List<String> ans = [];
    for (var word in sentence.split(" ")) {
      ans.add(root_tree.match(word));
    }
    return ans.join(" ");
  }
}

void main() {
  Solution test = Solution();

  List<String> dictionary = ["a", "abc", "abcd", "abe", "b", "bc", "bcd","kcd","kch"];
  String sentence = "aaaaa abee bcd ete kch kche";
  // a  abe b ete kch kch;
  var ans = test.replaceWords(dictionary, sentence);
  print(ans);

  // List<String> dict2 = ["cat","bat","rat"];
  // String s2 = "the cattle was rattled by the battery";
  // var ans = test.replaceWords(dict2, s2);
  // print(ans);
}
