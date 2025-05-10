import 'dart:math';

class Solution {
  int binaryGap(int n) {
    int? first_pos;
    int max_length = 0;
    String binary_n = n.toRadixString(2);
    for (int i = 0; i < binary_n.length; i++) {
      String bit = binary_n[i];
      if (bit == '1') {
        max_length = max(first_pos != null ? i - first_pos : 0, max_length);
        first_pos = i;
      }
    }
    return max_length;
  }
}

void main() {
  Solution solution = Solution();
  print(solution.binaryGap(5));
  print(solution.binaryGap(8));
  print(solution.binaryGap(22));
}
