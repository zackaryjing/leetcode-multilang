// problem: https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
    // first time not solved, not submitted;
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int all = accumulate(nums.begin(), nums.end(), 0);
        if (all % k > 0) {
            return false;
        }

        int per = all / k;
        ranges::sort(nums);
        if (nums.back() > per) {
            return false;
        }
        int n = nums.size();
        vector<bool> dp(1 << n, true);
        auto dfs = [&](this auto &&self, int s, int p) -> bool {
            if (s == 0) {
                return true;
            }
            if (not dp[s]) {
                return dp[s];
            }
            dp[s] = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] + p > per) {
                    break;
                }
                if ((s >> i) & 1) {
                    if (self(s ^ (1 << i), (p + nums[i]) % per)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs((1 << n) - 1, 0);
    }
};

int main(int argc, char *argv[]) { Solution test; }

//
// Created By jing At 2025-10-23 23:16
//
