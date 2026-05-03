// problem:
// https://leetcode.cn/problems/minimum-sum-of-four-digit-number-after-splitting-digits/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        for (int i = 0; i < 4; ++i) {
            nums.push_back(num % 10);
            num /= 10;
        }
        ranges::sort(nums);
        // ranges::sort(nums, [](const auto &a, const auto &b) { return a and (a < b or not b); });
        // show_vector(nums);
        return nums[0] * 10 + nums[1] * 10 + nums[2] + nums[3];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumSum(2903) << endl;
    cout << test.minimumSum(2932) << endl;
}

//
// Created By jing At 2026-05-03 17:57
//
