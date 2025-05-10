import 'dart:math';

class Solution {
  bool rotateString(String s, String goal) {
    if (s.length != goal.length) {
      return false;
    }
    bool valid = true;
    for (int i = 0; i < goal.length; i++) {
      valid = true;
      int j = 0;
      for (; j < goal.length - i; j++) {
        // print("${s[j]},${goal[j + i]}");
        if (s[j] != goal[j + i]) {
          valid = false;
        }
      }
      for (; j < s.length; j++) {
        // print("${s[j]},${goal[j + i - s.length]}");
        if (s[j] != goal[j + i - s.length]) {
          valid = false;
        }
      }
      if (valid) {
        return valid;
      }
      // print("");
    }
    return valid;
  }
}

void main() {
  Solution solution = Solution();
  print(solution.rotateString("asdfghjkl", "klasdfghj"));
}
