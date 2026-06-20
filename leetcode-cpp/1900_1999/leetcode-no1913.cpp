// problem:
// https://leetcode.cn/problems/maximum-product-difference-between-two-pairs/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxProductDifference(vector<int> &nums) {
        ranges::sort(nums);
        int n = nums.size();
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};


class Solution {
public:
    int maxProductDifference(vector<int> &nums) {
        int mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
        for (const auto& num : nums) {
            if (num >= mx1) {
                mx2 = mx1;
                mx1 = num;
            } else if (num > mx2) {
                mx2 = num;
            }
            if (num <= mn1) {
                mn2 = mn1;
                mn1 = num;
            } else if (num < mn2) {
                mn2 = num;
            }
        }
        // cout << "mx1: " << mx1 << endl;
        // cout << "mx2: " << mx2 << endl;
        // cout << "mn1: " << mn1 << endl;
        // cout << "mn2: " << mn2 << endl;
        return mx2 * mx1 - mn1 * mn2;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxProductDifference(temp_vector({5, 6, 2, 7, 4})) << endl;
    cout << test.maxProductDifference(temp_vector({4, 2, 5, 9, 7, 4, 8})) << endl;
}

//
// Created By jing At 2026-06-09 13:04
//
