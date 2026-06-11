// problem: https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp1(n), dp2(n);
        dp1[0] = max(nums[0], 0), dp2[0] = min(nums[0], 0);
        int mx = dp1[0], mn = dp2[0];
        for (int i = 1; i < n; ++i) {
            dp1[i] = max({dp1[i - 1] + nums[i], nums[i], 0});
            mx = max(mx, dp1[i]);
            dp2[i] = min({dp2[i - 1] + nums[i], nums[i], 0});
            mn = min(mn, dp2[i]);
            // show_vector(dp1);
        }
        return max(mx, -mn);
    }
};


class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        int n = nums.size();
        int dp1 = 0, dp2 = 0;
        int mx = max(dp1, 0), mn = min(dp2, 0);
        for (int i = 0; i < n; ++i) {
            dp1 = max(dp1 + nums[i], nums[i]);
            mx = max(mx, dp1);
            dp2 = min(dp2 + nums[i], nums[i]);
            mn = min(mn, dp2);
        }
        return max(mx, -mn);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxAbsoluteSum(temp_vector({1, -3, 2, 3, -4})) << endl;
    cout << test.maxAbsoluteSum(temp_vector({2, -5, 1, -4, 3, -2})) << endl;
}

//
// Created By jing At 2026-06-11 17:21
//
