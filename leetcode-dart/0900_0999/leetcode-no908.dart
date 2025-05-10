import 'dart:math';

class Solution {
  int smallestRangeI(List<int> nums, int k) {
    int maxNum = nums.reduce((int a, int b) => max(a, b));
    int minNum = nums.reduce((int a, int b) => min(a, b));
    if (maxNum - minNum < 2 * k) {
      return 0;
    } else {
      return maxNum - minNum - 2 * k;
    }
  }
}

void main() {
  Solution test = Solution();
  List<int> testset1 = [1, 2, 3, 4, 5];
  test.smallestRangeI(testset1, 10);
}
