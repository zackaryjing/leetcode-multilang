class Solution {
  List<int> selfDividingNumbers(int left, int right) {
    List<int> ans = [];
    for (int i = left; i <= right; i++) {
      var num = i;
      bool valid = true;
      while (num > 0) {
        // print(num);
        if (num % 10 == 0) {
          valid = false;
          break;
        }
        if (i % (num % 10)!= 0) {
          valid = false;
          break;
        } else {
          num ~/= 10;
        }
      }
      if (valid) {
        ans.add(i);
      }
    }
    return ans;
  }
}

void main() {
  Solution solution = Solution();
  print(solution.selfDividingNumbers(47, 85));
}
