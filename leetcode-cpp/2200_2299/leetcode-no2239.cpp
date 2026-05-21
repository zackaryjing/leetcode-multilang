// problem: https://leetcode.cn/problems/find-closest-number-to-zero/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int> &nums) {
        ranges::sort(nums, [](const auto &a, const auto &b) { return abs(a) == abs(b) ? a > b : abs(a) < abs(b); });
        return nums[0];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    test.findClosestNumber(temp_vector(
    {-100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000,
     -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000,
     -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000,
     -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000, -100000}));
}

//
// Created By jing At 2026-05-15 17:34
//
