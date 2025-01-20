class Solution {
  List<int> sortedSquares(List<int> nums) {
    List<int> sq_nums = nums.map((number) => (number * number)).toList();
    sq_nums.sort((a, b) => a.compareTo(b));
    return sq_nums;
  }
}

void main() {
  Solution solution = Solution();
  List<int> test = [-4, -1, 0, 3, 10];
  List<int> ans = solution.sortedSquares(test);
  print(ans);
}
