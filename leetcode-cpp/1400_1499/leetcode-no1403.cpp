// problem:
// https://leetcode.cn/problems/minimum-subsequence-in-non-increasing-order/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    vector<int> minSubsequence(vector<int> &nums) {
        multiset numbers(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int other = 0;
        multiset<int> res;
        while (true) {
            auto first = numbers.begin();
            other += *first;
            sum -= *first;
            if (sum <= other) {
                res = numbers;
                break;
            }
            numbers.erase(first);
        }
        return vector(res.rbegin(), res.rend());
    }
};


class Solution {
public:
    vector<int> minSubsequence(vector<int> &nums) {
        ranges::sort(nums);
        int sum = accumulate(nums.begin(), nums.end(), 0), other = 0, index = 0;
        vector<int> res;
        while (true) {
            auto first = nums[index++];
            other += first, sum -= first;
            if (sum <= other) {
                res.assign(nums.begin() + index - 1, nums.end());
                break;
            }
        }
        ranges::reverse(res);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.minSubsequence(temp_vector({4, 3, 10, 9, 8})));
    show_vector(test.minSubsequence(temp_vector({4, 4, 7, 6, 7})));
}

//
// Created By ASUS At 2026-05-26 15:01
//
