
class Solution {
  String toGoatLatin(String sentence) {
    List<String> words = sentence.split(" ");
    List<String> ans = [];
    int index = 0;
    for (var word in words) {
      index += 1;
      String temp = "";
      if (["A","E","I","O","U","a","e","i","o","u",].contains(word[0])) {
        temp = word;
        temp += "ma";
      } else {
        temp = word.substring(1);
        temp += word[0];
        temp += "ma";
      }
      for (int i = 0;i < index;i++) {
        temp += "a";
      }
      ans.add(temp);
    }
    return ans.join(" ");
  }
}

void main() {
  Solution solution = Solution();
  print(solution.toGoatLatin("I speak Goat Latin"));
}