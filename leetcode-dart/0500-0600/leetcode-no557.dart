
class Solution {
  String reverseWords(String s) {
    List<String> words = s.split(" ");
    int index = 0;
    for (var word in words) {
      words[index++] = word.split("").reversed.join();
    }
    return words.join(" ");
  }
}

void main() {
  Solution solution = Solution();
  print(solution.reverseWords("Let's take LeetCode contest"));
}
