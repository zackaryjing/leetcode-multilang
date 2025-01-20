import 'dart:math';

class Solution_s {
  bool hasGroupsSizeX(List<int> deck) {
    Map<int, int> numNum = {};
    for (var num in deck) {
      numNum[num] = (numNum[num] ?? 0) + 1;
    }
    List<int> times = [];
    for (var item in numNum.values) {
      times.add(item);
    }
    // print(times);

    int maxNum = times.reduce((int a, int b) => max(a, b));
    for (int i = 2; i <= maxNum; i++) {
      bool valid = true;
      for (var time in times) {
        if (time % i != 0) {
          valid = false;
        }
      }
      if (valid) {
        return true;
      }
    }
    return false;
  }
}

class Solution {
  bool hasGroupsSizeX(List<int> deck) {
    Map<int, int> numNum = {};
    for (var num in deck) {
      numNum[num] = (numNum[num] ?? 0) + 1;
    }
    List<int> times = [];
    for (var item in numNum.values) {
      times.add(item);
    }
    Function(int, int) getCommonDivisor = (int a, int b) {
      while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
        // a,b = b,(a % b);
      }
      return a;
    };
    int cnd = times[0];
    for (int i = 1; i < times.length; i++) {
      cnd = getCommonDivisor(cnd, times[i]);
    }
    if (cnd != 1) {
      return true;
    }
    return false;
  }
}

void main() {
  Solution test = Solution();
  List<int> deck = [1, 2, 3, 4, 4, 3, 2, 1];
  print(test.hasGroupsSizeX(deck));
}
