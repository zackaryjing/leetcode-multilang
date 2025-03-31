// problem: https://leetcode.cn/problems/k-inverse-pairs-array/
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        auto dp = vector(2, vector(k + 1, 0LL));
        constexpr int MASK = 1000000007;
        dp[1][0] = dp[0][0] = 1;
        for (int i = 2; i <= n; ++i) {
            int cur = i & 1, prev = !cur;
            for (int j = 1; j <= k; ++j) {
                if (j - i >= 0) {
                    dp[cur][j] = (dp[cur][j - 1] - dp[prev][j - i] + dp[prev][j] + MASK) % MASK;
                } else {
                    dp[cur][j] = (dp[cur][j - 1] + dp[prev][j] + MASK) % MASK;
                }
            }
        }
        return dp[n & 1][k];
    }
};


class Solution2 {
public:
    int kInversePairs(int n, int k) {
        auto dp = vector(n + 1, vector(k + 1, 0LL));
        constexpr int MASK = 1000000007;
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j - i >= 0) {
                    dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - i] + dp[i - 1][j] + MASK) % MASK;
                } else {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + MASK) % MASK;
                }
            }
        }
        return dp[n][k];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.kInversePairs(1000, 1000) << endl;
    cout << test.kInversePairs(3, 0) << endl;
    cout << test.kInversePairs(2, 1) << endl;
    cout << test.kInversePairs(3, 2) << endl;
    cout << test.kInversePairs(3, 1) << endl;
}


//
// Created by ASUS on 2025/3/26.
//
