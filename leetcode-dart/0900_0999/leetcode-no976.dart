class Solution {
  int largestPerimeter(List<int> nums) {
    nums.sort();
    int n = nums.length;
    for (int k = n - 1; k >= 2; k--) {
      int a = nums[k - 2];
      int b = nums[k - 1];
      int c = nums[k];
      if (a + b > c) {
        return a + b + c;
      }
    }
    return 0;
  }
}
