// problem: https://leetcode.cn/problems/left-and-right-sum-differences/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    vector<int> leftRightDifference(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res;
        res.reserve(nums.size());
        int preSum = 0;
        for (auto num: nums) {
            res.push_back(abs(sum - num - (preSum << 1)));
            preSum += num;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> leftRightDifference(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), preSum = 0;
        return nums | views::transform([&sum, &preSum](const int num) -> int { preSum += num;return abs(sum + num - 2 * preSum); }) |
               ranges::to<vector>();
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.leftRightDifference(temp_vector({10, 4, 8, 3})));
}

//
// Created By ASUS At 2026-05-29 14:48
//
