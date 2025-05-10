import 'dart:math';

class Solution {
  int numTilings(int n) {
    if (n == 0) {
      return 0;
    }
    int MOD = pow(10,9).toInt() + 7;
    List<int> full = List.filled(n + 1, 0), half = List.filled(n + 1, 0);
    full[0] = 1;
    for (int i = 1; i <= n; i++) {
      if (i > 0) {
        full[i] = (full[i - 1]) + half[i - 1] % MOD;
        half[i] = half[i - 1] % MOD;
      }
      if (i > 1) {
        full[i] += full[i - 2] % MOD;
        half[i] += full[i - 2] * 2 % MOD;
      }
    }
    print(full);
    print(half);
    return full[n] % MOD;
  }
}

void main() {
  Solution test = Solution();
  for (int i = 0; i < 10; i++) {
    print(test.numTilings(i));
  }
}
