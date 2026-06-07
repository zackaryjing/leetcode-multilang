// problem: https://leetcode.cn/problems/apply-operations-to-an-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        ranges::stable_sort(nums, [](const uint32_t a, const uint32_t b) { return not b and a; });
        return nums;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.applyOperations(temp_vector({1, 2, 2, 1, 1, 0})));
    show_vector(test.applyOperations(temp_vector({0, 1})));
}

//
// Created By jing At 16:52
//
