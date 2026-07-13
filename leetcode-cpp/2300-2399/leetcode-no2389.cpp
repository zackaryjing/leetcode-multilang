// problem:
// https://leetcode.cn/problems/longest-subsequence-with-limited-sum/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        ranges::sort(nums);
        int cur = 0;
        for (auto &num: nums) num += cur, cur = num;
        vector<int> res;
        for (const int query: queries) res.push_back(ranges::upper_bound(nums, query) - nums.begin());
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.answerQueries(temp_vector({4, 5, 2, 1}), temp_vector({3, 10, 21})));
}

//
// Created By ASUS At 2026-07-12 17:09
//
