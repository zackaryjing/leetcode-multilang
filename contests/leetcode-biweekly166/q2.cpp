// problem: https://leetcode.cn/problems/climbing-stairs-ii/description/
#include <iostream>
#include <limits.h>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int> &costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 3; j < i; ++j) {
                if (j >= 0) {
                    dp[i] = min(dp[i], dp[j] + costs[i - 1] + (i - j) * (i - j));
                }
            }
        }
        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.climbStairs(4, temp_vector({1, 2, 3, 4})) << endl;
    cout << test.climbStairs(4, temp_vector({5, 1, 6, 2})) << endl;
    cout << test.climbStairs(3, temp_vector({9, 8, 3})) << endl;
}

//
// Created By Zackary At 2025-09-27 23:23
//
