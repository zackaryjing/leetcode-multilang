class Solution {
  int repeatedNTimes(List<int> nums) {
    Map<int, int> myData = {};
    for (var num in nums) {
      if (myData[num] != null) {
        return num;
      } else {
        myData[num] = 1;
      }
    }
    // print(myData);
    return 0;
  }
}

/*
adasdf
//  */

void main() {
  Solution solution = Solution();
  List<int> test = [1, 2, 1, 3, 4];
  print(solution.repeatedNTimes(test));
}
