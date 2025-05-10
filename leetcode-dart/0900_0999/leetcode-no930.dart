class Solution2 {
  /// It actually works, but just too complex
  int numSubarraysWithSum(List<int> nums, int goal) {
    int ans = 0;
    int prevZero = 0;
    int nextZero = 0;
    int start = 0, end = 0;
    int total = nums[0];
    if (goal < 1) {
      int zeroCnt = 0;
      for (int i = 0; i < nums.length; i++) {
        if (nums[i] == 0) {
          zeroCnt++;
        } else {
          ans += zeroCnt * (zeroCnt + 1) ~/ 2;
          zeroCnt = 0;
        }
      }
      if (nums.last == 0) {
        ans += zeroCnt * (zeroCnt + 1) ~/ 2;
      }
      return ans;
    }
    while (end <= nums.length - 1) {
      if (total < goal) {
        if (end < nums.length - 1) {
          while (total < goal && end < nums.length - 1) {
            if (nums[++end] == 0) {
              // print("true");
              while (end < nums.length - 1 && nums[end] == 0) end++;
              if (nums[end] == 1) {
                total += 1;
              } else {
                break;
              }
            } else {
              // print("false");
              total += 1;
            }
          }
        } else {
          break;
        }
      } else {
        if (nums[start] == 0) {
          while (nums[start] == 0) {
            prevZero++;
            start++;
          }
        }

        nextZero = 0;
        for (int i = end + 1; i < nums.length; i++) {
          if (nums[i] == 0) {
            nextZero += 1;
          } else {
            break;
          }
        }

        // print("start: $start, end: $end, prev: $prevZero,next:$nextZero total: $total");
        ans += (nextZero + 1) * (prevZero + 1);

        start += 1;
        prevZero = 0;
        total -= 1;
      }
    }
    return ans;
  }
}

class Solution {
  int numSubarraysWithSum(List<int> nums, int goal) {
    int sum = 0;
    Map<int, int> cnt = Map();
    int ret = 0;
    for (var num in nums) {
      cnt[sum] = cnt[sum] != null ? cnt[sum]! + 1 : 1;
      sum += num;
      ret += cnt[sum - goal] ?? 0;
    }
    return ret;
  }
}

void main() {
  Solution test = Solution();
  // List<int> eg1 = [1, 0, 1, 0, 1];
  // int ans1 = test.numSubarraysWithSum(eg1, 2);
  // print(ans1);
  // List<int> eg2 = [0, 0, 0, 0, 1];
  // int ans2 = test.numSubarraysWithSum(eg2, 2);
  // print(ans2);
  // List<int> eg3 = [0, 1, 1, 1, 1];
  // int ans3 = test.numSubarraysWithSum(eg3, 3);
  // print(ans3);
  // List<int> eg4 = [0, 0, 0, 0, 0, 0, 0, 1, 0, 0];
  // int ans4 = test.numSubarraysWithSum(eg4, 2);
  // print(ans4);
  List<int> eg5 = [0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0];
  int ans5 = test.numSubarraysWithSum(eg5, 5);
  print(ans5);
}
