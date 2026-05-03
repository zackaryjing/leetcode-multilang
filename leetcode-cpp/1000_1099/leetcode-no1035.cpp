// problem: https://leetcode.cn/problems/uncrossed-lines/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> n1, n2;
        n1.reserve(n), n2.reserve(m);
        unordered_set<int> n2set(nums2.begin(), nums2.end());
        unordered_set<int> n1set;
        for (const auto num: nums1)
            if (n2set.contains(num)) {
                n1.push_back(num);
                n1set.insert(num);
            }
        for (const auto num: nums2)
            if (n1set.contains(num)) n2.push_back(num);
        int newn = n1.size(), newm = n2.size();
        vector dp(newn, vector<int>(newm));
        for (int i = 0; i < newn; ++i) {
            for (int j = 0; j < newm; ++j) {
                if (n1[i] == n2[j])
                    if (i > 0 and j > 0)
                        dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
                    else if (i > 0)
                        dp[i][j] = max(1, dp[i - 1][0]);
                    else if (j > 0)
                        dp[i][j] = max(1, dp[0][j - 1]);
                    else
                        dp[i][j] = 1;
                else {
                    if (j > 0) dp[i][j] = dp[i][j - 1];
                    if (i > 0) dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                }
            }
        }
        if (newn == 0 || newm == 0) return 0;
        return dp[newn - 1][newm - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxUncrossedLines(temp_vector({1, 4, 2}), temp_vector({1, 2, 4})) << endl;
    cout << test.maxUncrossedLines(temp_vector({2, 5, 1, 2, 5}), temp_vector({10, 5, 2, 1, 5, 2})) << endl;
}

//
// Created By jing At 2026-05-03 23:26
//
