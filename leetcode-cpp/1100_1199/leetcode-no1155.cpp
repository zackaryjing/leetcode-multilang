// problem: https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector dps(2, vector<int64_t>(target + 1, 0ll));
        vector dp(2, vector<int64_t>(target + 1, 0ll));
        const int64_t mask = 1000000007;
        dps[0] = vector<int64_t>(target + 1, 1ll);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i % 2][j] = (dps[not((i - 1) & 1)][j - 1] - (j > k ? dps[not((i - 1) & 1)][j - k - 1] : 0ll)) % mask;
                dps[i % 2][j] = (dp[i][j] + dps[i][j - 1]) % mask;
            }
        }
        return (dp[n][target] + mask) % mask;
    }
};


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector dps(n + 1, vector<int64_t>(target + 1, 0ll));
        vector dp(n + 1, vector<int64_t>(target + 1, 0ll));
        const int64_t mask = 1000000007;
        dps[0] = vector<int64_t>(target + 1, 1ll);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = (dps[i - 1][j - 1] - (j > k ? dps[i - 1][j - k - 1] : 0ll)) % mask;
                dps[i][j] = (dp[i][j] + dps[i][j - 1]) % mask;
            }
        }
        return (dp[n][target] + mask) % mask;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numRollsToTarget(1, 6, 3) << endl;
    cout << test.numRollsToTarget(2, 6, 7) << endl;
    cout << test.numRollsToTarget(20, 20, 200) << endl;
    // cout << test.numRollsToTarget(30, 30, 500) << endl;
}

//
// Created By jing At 2026-05-22 20:17
//
