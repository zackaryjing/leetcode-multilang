// problem: https://leetcode.cn/problems/find-target-indices-after-sorting-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        ranges::sort(nums);
        vector<int> res;
        auto pos = ranges::lower_bound(nums, target);
        for (; pos < nums.end(); ++pos) {
            if (*pos != target) break;
            res.push_back(pos - nums.begin());
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.targetIndices(temp_vector({1, 2, 5, 2, 3}), 2));
}

//
// Created By jing At 2026-06-06 18:00
//
