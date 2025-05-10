import 'dart:math';

class Solution {
  int firstMissingPositive(List<int> nums) {
    int N = nums.length;
    int i = 0;

    for (i = 0; i < N; i++) {
      if (nums[i] <= 0) {
        nums[i] = -nums[i] + N + 1;
      }
    }

    for (i = 0; i < N; i++) {
      int numabs = nums[i].abs();
      if (numabs <= N) {
        nums[numabs - 1] = -nums[numabs - 1].abs();
      }
    }
    for (i = 1; i <= N; i++) {
      if (nums[i - 1] > 0) {
        return i;
      }
    }
    return N + 1;
  }
}

void main() {
  Solution solution = Solution();
  List<int> test1 = [1, 2, 0];
  List<int> test2 = [3, 4, -1, 1];
  List<int> test3 = [7, 8, 9, 11, 12];
  List<int> test4 = [1, 1];
  print(solution.firstMissingPositive(test1));
  print(solution.firstMissingPositive(test2));
  print(solution.firstMissingPositive(test3));
  print(solution.firstMissingPositive(test4));
}
