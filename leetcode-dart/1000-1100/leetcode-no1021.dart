import "dart:core";

class Solution {
  String removeOuterParentheses(String s) {
    if (s.isEmpty) return "";
    String ans = "";
    int cnt = 0;
    for (var char in s.split('')){
      if (char == ")") {
        cnt--;
      }
      if (cnt != 0) {
        ans += char;
      }
      if (char == "(") {
        cnt++;
      }
    }
    return ans;
  }
}

void main() {
  Solution test = Solution();
  print(test.removeOuterParentheses("(()())(())"));
  print(test.removeOuterParentheses("(()())(())(()(()))"));

}
